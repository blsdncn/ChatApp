#include "socketutil.h"
#include <unistd.h>
#include <pthread.h>


int main(int argc, char *argv[]) {
    int opt;
    char* ip = "127.0.0.1";
    while((opt = getopt(argc,argv,"a:"))!= -1){
        switch(opt){
            case 'a':
                ip = optarg;
        }
    }
    int socketFD = createTCPIPv4Socket();
    struct sockaddr_in *address = createIPv4Address(ip, 2000);
    int result = connect(socketFD, (struct sockaddr*)address, sizeof(*address));

    if (result == 0) {
        printf("Connection has been established\n");
    } else {
        perror("Connection failed\n");
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t lineSize = 0;
    printf("Write a message to send to the server...\n");

    while (1) {
        ssize_t charCount = getline(&line, &lineSize, stdin);
        line[strcspn(line, "\n")] = 0; // remove newline character

        if (charCount > 0) {
            ssize_t amountSent = send(socketFD, line, strlen(line), 0);
            if (strcmp(line, "exit") == 0) {
                printf("Exiting\n");
                break;
            }
            if (amountSent < 0) {
                perror("Send failed\n");
                break;
            }
        }
    }
    free(line);
    close(socketFD);

    return 0;
}


