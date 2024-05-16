#include "socketutil.h"

int main(){

    int serverSocketFD = createTCPIPv4Socket();
    struct sockaddr_in *serverAddress = createIPv4Address("",2000);

    int result = bind(serverSocketFD,serverAddress,sizeof(*serverAddress));
    if(result == 0){
        printf("socket was bound successfully\n");
    }

    int listenResult = listen(serverSocketFD,10);

    struct sockaddr_in clientAddress;
    int clientAddressSize = sizeof(struct sockaddr_in);
    int clientSocketFD = accept(serverSocketFD,&clientAddress,&clientAddressSize);


    char buffer[1024];
    recv(clientSocketFD,buffer,1024,0);


    printf("response was %s\n",buffer);

    return 0;
}