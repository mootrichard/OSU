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
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fcntl.h>

int main(int argc, char const *argv[]) {

  // Ensure that a port number has been specified, additionally, prompt with correct usage
  if(argc != 2){
    std::cerr << "ERROR. Format is: ./ftpserver <port#>" << std::endl;
    exit(1);
  }

  return 0;
}

void startup (){

};

void handleRequest(){

};
