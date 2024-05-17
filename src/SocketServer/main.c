#include "socketutil.h"

int main(){

    int serverSocketFD = createTCPIPv4Socket();
    struct sockaddr_in *serverAddress = createIPv4Address("",2000);
    struct sockaddr_in clientAddress;
    int clientAddressSize = sizeof(struct sockaddr_in);
    char clientIP[INET_ADDRSTRLEN];

    int result = bind(serverSocketFD,serverAddress,sizeof(*serverAddress));
    if(result == 0){
        printf("Socket was bound successfully\n");
    }

    int listenResult = listen(serverSocketFD,10);
    char buffer[1024];

    while(true){
        int clientSocketFD = accept(serverSocketFD,&clientAddress,&clientAddressSize);
        if(clientSocketFD<0){
            perror("Accpet failed");
            continue;
        }

        if(inet_ntop(AF_INET,&clientAddress.sin_addr,clientIP,INET_ADDRSTRLEN)==NULL){
            perror("inet_ntop");
            close(clientSocketFD);
            continue;
        }
        printf("Client %s connected\n",clientIP);
        while(true){
            memset(buffer,0,sizeof(buffer)); //clear buffer
            ssize_t bytesReceived = recv(clientSocketFD,buffer,1024,0);
            if(bytesReceived < 0){
                perror("recv failed");
                break;
            }
            buffer[bytesReceived] = '\0';

            if(strcmp(buffer,"exit")==0){
                printf("Client exited.");
                break;
            }
            printf("Message recieved from client: %s\n",buffer);
        }
        close(clientSocketFD);
    }

    close(serverSocketFD);
    return 0;
}