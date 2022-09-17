#include "server.h"

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

int sockfd, connfd;

void init_server(struct sockaddr_in *servaddr) {
    
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
       printf("socket creation failed...\n");
       exit(0);
    }
    else
          printf("Socket successfully created..\n");
    bzero(servaddr, sizeof(*servaddr));
  
    // assign IP, PORT
    (*servaddr).sin_family = AF_INET;
    //servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    (*servaddr).sin_port = htons(PORT);
  
    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)servaddr, sizeof(*servaddr))) != 0) {
       printf("socket bind failed...\n");
       exit(0);
    }
    else
       printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
          printf("Listen failed...\n");
        exit(0);
    }
    else
       printf("Server listening..\n");
}

void close_server() {
    close(sockfd);
}

int send_to_client(void *buffer) {
    return write(connfd, buffer, sizeof(buffer));
}

void accept_confirmation(struct sockaddr_in *cli) {
  
    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA*)cli, sizeof(*cli));
    if (connfd < 0) {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");
}
