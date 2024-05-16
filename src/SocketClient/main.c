#include "socketutil.h"

int main(){

    int socketFD = createTCPIPv4Socket();
    struct sockaddr_in *address = createIPv4Address("127.0.0.1",2000);
    int result = connect(socketFD,address,sizeof(*address));

    if(result == 0){
        printf("Connection has been established\n");
    }

    char* message;
    message = "GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";
    send(socketFD,message,strlen(message),0);

    char buffer[1024];
    recv(socketFD,buffer,1024,0);
    printf("Response was %s\n",buffer);

    return 0;
}
