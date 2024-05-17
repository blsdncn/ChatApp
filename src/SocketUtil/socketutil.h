#ifndef SOCKETUTIL_SOCKETUTIL_H
#define SOCKETUTIL_SOCKETUTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdbool.h>

/**
 * Creates an IPv4 address structure.
 *
 * @param ip The IP address as a string.
 * @param port The port number.
 * @return A pointer to the created sockaddr_in structure.
 */
struct sockaddr_in *createIPv4Address(char *ip, int port);

/**
 * Creates a TCP/IP version 4 socket.
 *
 * @return The created socket file descriptor.
 */
int createTCPIPv4Socket();

#endif //SOCKETUTIL_SOCKETUTIL_H