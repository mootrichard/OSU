/**
 * Author: Richard Moot
 * Description: Chat Server for communicating over a socket in a back and forth manner
 * Date: May 1, 2016
 *
 * Credits:
 * 		http://beej.us/guide/bgnet/output/html/multipage/clientserver.html
 * 		http://www.linuxhowtos.org/C_C++/socket.htm
 *  The above websites were very influential in creating the server client due to their excellent
 *  examples on how to establish the sockets for communicating.
 */

#include <ctype.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>

#define PORT 33221  // Port used for chat server
#define BACKLOG 10    // Number of pending connections that the queue will hold

void error (char *msg) {
  perror(msg);
  exit(1);
}

/** runChatSession
 * [Handles the chat session for the server by connecting the Server and the Client]
 * @socket: socket that communication is taking place on for sending and receiving messages
 */

void runChatSession(int socket){
  char serverHandle[] = "Wonder_Burr";
  char received_buffer[500];
  char sent_buffer[500];
  bool quit = false;
  int receivedStatus;

  while (!quit){ // Continue chat until having quit or client quits (or disconnects)
    bzero(received_buffer, 500);
    bzero(sent_buffer, 500);

    // Storing whether or not a message has been received, if 0 then client has disconnected
    receivedStatus = recv(socket, received_buffer, 500, 0);

    // Notifying that the client has disconnected
    if(receivedStatus == 0){
      std::cout << "Client has disconnected..." << std::endl;
      return;
    }

    // Checking if the client actually sent a quit command
    if(strstr(received_buffer, "\\quit") != NULL){
      std::cout << "Client has left chat..." << std::endl;
      return; // Exiting out since the client has left
    }

    // Displaying message out to console from the Client
    printf("%s\n", received_buffer);

    // Promting for the response message from the Server to the Client
    std::cout << serverHandle << "> ";
    fgets(sent_buffer, 500, stdin);

    // Checking if a quit command has been received
    if(strstr(sent_buffer, "\\quit") == NULL){
      std::string temp = "";
      temp.append(serverHandle);
      temp.append(":> ");
      temp.append(sent_buffer);
      write(socket, temp.c_str(), temp.length());
    }
    else{ // Exiting out since Sever user requested to quit
      quit == true;
      close(socket);
      std::cout << "Client has disconnected..." << std::endl;
      return;
    }
  }
  return;
}

int main (int argc, char *argv[]) {
  int sockfd, new_sockfd, msg_length, portno, processId;
  socklen_t client_addr_len;
  struct sockaddr_in server_addr, client_addr;

  // Establishing server side of socket for communicating on
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0){ // Ensuring that socket opened, otherwise throwing an error
    error("ERROR trying to open socket");
  }

  // Clearing out server address to be safe
  bzero((char *) &server_addr, sizeof(server_addr));

  // Checking if a port was specified, otherwise using default
  if(argc < 2){
    portno = PORT;
    std::cout << "Using default port of " << PORT << std::endl;
    std::cout << "(next time you can specify your port when running)" << std::endl;
  }
  else if (argc >= 2){
    portno = atoi(argv[1]);
    std::cout << "Using port: " << portno << std::endl;
  }

  // Setting server IP address information
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(portno);

  // Binding process to the socket to communicate on
  bind(sockfd, (struct sockaddr *) & server_addr, sizeof(server_addr));
  listen(sockfd, BACKLOG);

  // Notifying where our chat server is running on the machine
  std::cout << "Chat server running on port " << portno << ", waiting for Client to connect..." << std::endl;


  client_addr_len = sizeof(client_addr);

  while(1){ // Leaving in a loop to run until SIGINT is given to terminate
    new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len);

    processId = fork();
    if(processId == 0) { // We have successfully forked!
      std::cout << "Client Connected" << std::endl;
      close(sockfd); // Closing old socket
      runChatSession(new_sockfd); // Running chat session on newly created socket
      exit(0);
    }
    else {
      close(new_sockfd);
    }

  }

  close(sockfd);
  return 0;
}
