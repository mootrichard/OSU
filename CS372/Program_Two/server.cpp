/**
 * Author: Richard Moot
 * 		CS372 - Project 2 - FTP Server
 * Date: May 29, 2016
 * Description:
 * 		This is the server component of the FTP Server/Client interation. The user
 * 		must provide a port number for the server to run on as an argument. The server
 * 		has several commadns that are received over the command port that allow the user
 * 		to list the directory contents and retrieve files from the server.
 *
 * 		The server utilizes socket connections and will remain listening on the specified
 * 		port for a connection to be made. Once the connection is established the client
 * 		can then specify which port they would like the data to be received on and the server
 * 		will deliver files over that port.
 *
 * Sources:
 * 		http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html
 * 		http://www.linuxhowtos.org/C_C++/socket.htm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <csignal>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <fcntl.h>
#include <dirent.h>
#include <assert.h>

// Function Prototypes
void signalHandler(int signum);
void error (std::string msg);
void runFTP(int commPort, int newSocket);
char *handleRequest(int commSocket);
int setupSocket(int commPort);
char** getDirectory(int dataSocket, char** dir);

// Main execution of FTP Server
int main(int argc, char const *argv[]) {

  // Ensure that a port number has been specified, additionally, prompt with correct usage
  if(argc != 2){
    std::cerr << "ERROR. Format is: ./ftpserver <port#>" << std::endl;
    exit(1);
  }

  // Gracefully handling signal interrupts for shutting down the server
  signal(SIGINT, signalHandler);

  // Initializing FTP Server
  int commPort = atoi(argv[1]);
  int serverSocket = setupSocket(commPort);

  runFTP(commPort, serverSocket);

  return 0;
}

/**
 * [setupSocket description]
 * @param  commPort [description]
 * @return          [description]
 */
int setupSocket(int commPort){
  int newSocket = socket(AF_INET, SOCK_STREAM, 0);
  if(newSocket < 0){
    error("ERROR trying to open socket");
  };

  struct sockaddr_in serverAddr;

  bzero((char *) &serverAddr, sizeof(serverAddr));

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = INADDR_ANY;
  serverAddr.sin_port = htons(commPort);

  if(bind(newSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr))< 0){
    error("Error in binding to provided port");
    exit(1);
  };

  listen(newSocket, 5);

  return newSocket;
};

/**
 * [runFTP  description]
 * @param commPort  [description]
 * @param newSocket [description]
 */
void runFTP (int commPort, int newSocket){
  while(true){
    int commSocket, dataSocket, dataPort, newServerSocket;
    char *incComm, *fileName, *dPortString;
    char ** currentDirectory = NULL;

    struct sockaddr_in clientAddr; // Client's address stored here

    socklen_t clientLength = sizeof(clientAddr); // Creating length for accept() of client's address

    std::cout << "Server running and listening on port " << commPort << "..." << std::endl;

    // Listening on the Command socket for any requests from client(s)
    commSocket = accept(newSocket, (struct sockaddr *) &clientAddr, &clientLength);
    if(commSocket < 0){ // Verifying that we successuflly accepted
      error("Error: Command socket failed to initialize.\n");
      exit(1);
    }

    // Parsing client's request to determine the command they sent
    incComm = handleRequest(commSocket);

    // Notify server console which command was sent and the client who did it
    std::cout << "RECEIVED: " << incComm << " Command received from " << inet_ntoa(clientAddr.sin_addr) << ":" << commPort << std::endl;

    // Check if its a get request first, since we want to say the filename
    if(strcmp(incComm, "-g") == 0){
      fileName = handleRequest(commSocket);
      std::cout << "REQUESTED: " << "File: '" << fileName << "' has been requested."  << std::endl;
    };

    // We need to pull out the specified data port no matter what
    dPortString = handleRequest(commSocket);
    dataPort = atoi(dPortString);

    // Notify we intend to establish a connection at the specified client address and port
    std::cout << "ATTEMPTING: Establishing data connection at " << inet_ntoa(clientAddr.sin_addr) << ":" << dataPort << std::endl;
    newServerSocket = setupSocket(dataPort);

    // Attempting to connect to the provided data port
    dataSocket = accept(newServerSocket, (struct sockaddr *) &clientAddr, &clientLength);
    if(dataSocket < 0){
      error("Error on establishing data socket connection");
      exit(1);
    }

    currentDirectory = getDirectory(dataSocket, currentDirectory);

    // We have established a Data Connection
    std::cout << "SUCCESS: Data connection established at: " << inet_ntoa(clientAddr.sin_addr) << ":" << dataPort << std::endl;



    // Handling request to view the file directory
    if(strcmp(incComm, "-l") == 0){
      std::cout << "List command sent" << std::endl;
    }

    close(dataSocket);
    close(newServerSocket);
    close(commSocket);
  }
};

/**
 * [handleRequest description]
 * @param  commSocket [description]
 * @return            [description]
 */
char *handleRequest(int commSocket){
  unsigned short packetLen;
  unsigned short dataLen;
  char* req;
  int reqByteSize = 0;

  int n = recv(commSocket, &packetLen, 2, 0);
  packetLen = ntohs(packetLen);

  dataLen = packetLen - sizeof(packetLen);

  req = (char *)malloc(dataLen * sizeof(char));

  while(reqByteSize < dataLen){
    n = recv(commSocket, req + reqByteSize, (dataLen - reqByteSize),0);
    reqByteSize += n;
  }
  req[dataLen] = '\0';

  return req;
};

void sendFile(int dataSocket, char *fileName){
  bool fileExists = false;


};

char **getDirectory(){
  char** currentDirectory = NULL;
  struct dirent *directoryEntry;
  DIR *directory;
  int filesAmount = 0;

  if((directory = opendir(".")) != NULL){
    while((directoryEntry = readdir(directory)) != NULL){
      if(currentDirectory == NULL){
        currentDirectory = (char **)malloc(sizeof(char *));
      } else {
        currentDirectory = (char **)realloc(currentDirectory, (filesAmount + 1) * sizeof(char *));
      }
      assert(currentDirectory != NULL);

      currentDirectory[filesAmount] = (char *)malloc((strlen(directoryEntry->d_name) + 1) * sizeof(char));
      assert(currentDirectory[filesAmount] != NULL);

      currentDirectory[filesAmount] = directoryEntry->d_name;
      filesAmount += 1;
    }
    closedir(directory);
  } else {
    error("ERROR: failed to access directory");
    exit(1);
  }

  return currentDirectory;
};

/**
 * [signalHandler description]
 * @param signum [description]
 */
void signalHandler(int signum){
  std::cout << "Server shutting down..." << std::endl;
  exit(signum);
}

/**
 * [error  description]
 * @param msg [description]
 */
void error (std::string msg) {
  std::cerr << msg << std::endl;
  exit(1);
}
