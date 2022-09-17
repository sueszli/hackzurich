#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

void init_server(struct sockaddr_in*);
void close_server();
int send_to_client(void*);
void accept_confirmation(struct sockaddr_in*);

#endif