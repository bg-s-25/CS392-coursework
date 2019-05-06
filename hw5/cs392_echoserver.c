/**
    Title  : CS 392 B - HW Assignment 5
    Desc   : Socket-based echo server
    Name   : Bobby Georgiou
    Date   : 05/07/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "cs392_log.h"

#define MAXCLIENTS 5
#define MAXMSG 1024

/**
 * Read and echo message from a client
 */
void read_client(int clientsock) {
    char buffer[MAXMSG];
    int data = read(clientsock, buffer, MAXMSG);
    if (data < 0) {
        perror("read");
        exit(1);
    } else {
        // printf("Server got message: %s\n", buffer);
        // relay message
        if (send(clientsock, buffer, data, 0) < 0) {
            perror("send");
            exit(1);
        }
    }
}

/**
 * Setup server socket and listener with provided IP and port
 */
void run_server(int port) {
    int serversock, clientsock;
    struct sockaddr_in echoserver, echoclient;

    // init socket
    serversock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    memset(&echoserver, 0, sizeof(echoserver));
    echoserver.sin_family = AF_INET;
    echoserver.sin_addr.s_addr = htonl(INADDR_ANY);
    echoserver.sin_port = htons(port);
    if (bind(serversock, (struct sockaddr *)&echoserver, sizeof(echoserver)) < 0) {
        perror("bind");
        exit(1);
    }

    // listen for connections
    if (listen(serversock, MAXCLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    // wait for connection and accept
    int clientlen = sizeof(echoclient);
    while (1) {
        char buffer[MAXMSG];
        clientsock = accept(serversock, (struct sockaddr *)&echoclient, &clientlen);
        if (clientsock < 0) {
            perror("accept");
            exit(1);
        } else {
            cs392_socket_log(echoclient.sin_addr, echoserver.sin_port);
            read_client(clientsock);
        }

        // echo message from client
        if (send(clientsock, buffer, strlen(buffer), 0) < 0) {
            perror("send");
            exit(1);
        }

        // close connection with client
        close(clientsock);
    }
}

int main(int argc, char ** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./cs392_echoserver <port>\n");
        exit(1);
    }

    // ensure that port input is valid
    char * res;
    long portlong = strtol(argv[1], &res, 10);
    if (res == argv[1]) {
        fprintf(stderr, "Error: invalid port number.\n");
        exit(1);
    }

    // run server on given port
    run_server((int)portlong);

    return 0;
}
