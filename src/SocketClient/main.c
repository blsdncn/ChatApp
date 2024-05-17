#include "socketutil.h"

int main(){

    int socketFD = createTCPIPv4Socket();
    struct sockaddr_in *address = createIPv4Address("127.0.0.1",2000);
    int result = connect(socketFD,address,sizeof(*address));

    if(result == 0){
        printf("Connection has been established\n");
    }


    char *line = NULL;
    size_t lineSize = 0;
    printf("Write a message to send to the server...\n");

    while(true){
        ssize_t charCount = getline(&line,&lineSize,stdin); 
        if(charCount>0){
            if(strcmp(line,"exit\n")==0){
                break;
            }
        ssize_t amountSent = send(socketFD,line,charCount,0);
        }
    }

    char buffer[1024];
    recv(socketFD,buffer,1024,0);
    printf("Response was %s\n",buffer);

    return 0;
}

