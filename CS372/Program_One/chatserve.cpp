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

void runChatSession(int socket){
  std::string serverHandle = "Wonder_Burr";
  char received_buffer[500];
  char sent_buffer[500];
  bool quit = false;

  while (!quit){
    bzero((char *) &received_buffer, 500);

    if(recv(socket, received_buffer, 500, 0) == 0){
      std::cout << "Client has disconnected..." << std::endl;
      return;
    }

    printf("%s", received_buffer);
    std::cout << "Reply: ";
    fgets(sent_buffer, 500, stdin);

    if(strcmp(sent_buffer, "\\quit") != 0){
      write(socket, sent_buffer, strlen(sent_buffer));
    }
    else{
      close(socket);
      std::cout << "Client has disconnected..." << std::endl;
      quit == true;
      return;
    }
  }
  return;
}

int main (int argc, char *argv[]) {
  int sockfd, new_sockfd, msg_length, portno;
  socklen_t client_addr_len;
  struct sockaddr_in server_addr, client_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0){
    error("ERROR trying to open socket");
  }

  bzero((char *) &server_addr, sizeof(server_addr));
  portno = PORT;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(portno);

  bind(sockfd, (struct sockaddr *) & server_addr, sizeof(server_addr));
  listen(sockfd, BACKLOG);

  std::cout << "Chat server running on port " << PORT << ", waiting for Client to connect..." << std::endl;

  client_addr_len = sizeof(client_addr);

  while(1){
    new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len);


  }

  close(new_sockfd);
  close(sockfd);
}
