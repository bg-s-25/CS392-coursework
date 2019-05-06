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
#include <arpa/inet.h>

#define MAXMSG 1024

/**
 * Read and print echoed message from the server
 */
void read_server(int clientsock) {
    char buffer[MAXMSG];
    int data = read(clientsock, buffer, MAXMSG);
    if (data < 0) {
        perror("read");
        exit(1);
    } else {
        printf("Client got message: %s\n", buffer);
    }
}

/**
 * Setup client socket with provided IP and port
 */
int run_client(char * ip, int port) {
    int serversock, clientsock;
    struct sockaddr_in echoserver, echoclient;

    // init socket
    clientsock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    memset(&echoserver, 0, sizeof(echoserver));
    echoserver.sin_family = AF_INET;
    echoserver.sin_addr.s_addr = inet_addr(ip);
    echoserver.sin_port = htons(port);

    // connect to client
    if (connect(clientsock, (struct sockaddr *)&echoserver, sizeof(echoserver)) < 0) {
        perror("connect");
        exit(1);
    }

    return clientsock;
}

int main(int argc, char ** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./cs392_echoclient <ip> <port>\n");
        exit(1);
    }

    // ensure that port input is valid
    char * res;
    long portlong = strtol(argv[2], &res, 10);
    if (res == argv[2]) {
        fprintf(stderr, "Error: invalid port number.\n");
        exit(1);
    }

    // connect to server
    int clientsock = run_client(argv[1], (int)portlong);

    // prompt for message to send
    char msg[MAXMSG];
    printf("Enter message: ");
    fgets(msg, MAXMSG, stdin);
    msg[strcspn(msg, "\n")] = 0;

    // send message
    if (send(clientsock, msg, MAXMSG, 0) < 0) {
        perror("send");
        exit(1);
    }
    read_server(clientsock);

    return 0;
}
