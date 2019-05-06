/**
    Title  : CS 392 B - HW Assignment 5
    Desc   : Socket-based echo server
    Name   : Bobby Georgiou
    Date   : 05/07/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/**
 * Log client information to file
 */
void cs392_socket_log(struct in_addr ip, int port) {
    char * ipstr = inet_ntoa(ip);
    port = ntohs(port);

    // open log file
    FILE * fp = fopen("cs392_socket.log", "a");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open log file.\n");
        exit(1);
    }

    // write client info to log file
    fprintf(fp, "%s", ipstr);
    fprintf(fp, ":%d\n", port);

    // close log file
    fclose(fp);
}
