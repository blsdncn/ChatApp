#include "socketutil.h"

struct sockaddr_in *createIPv4Address(char *ip, int port){
    struct sockaddr_in *address = malloc(sizeof(struct sockaddr_in));
    address->sin_port = htons(port); //host to network short "hots()" converts to proper endian?
    address->sin_family = AF_INET;

    if(strlen(ip)==0){
        address->sin_addr.s_addr = INADDR_ANY;
    } else{
    inet_pton(AF_INET,ip,&address->sin_addr);
    }

    return address;
}

int createTCPIPv4Socket(){ return socket(AF_INET,SOCK_STREAM,0); }