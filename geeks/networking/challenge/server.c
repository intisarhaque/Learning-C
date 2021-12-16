#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void){
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(int hSocket){
    int iRetval = -1;
    int clientPort = 12345;

    struct sockaddr_in remote = {0};

    //internet address family
    remote.sin_family = AF_INET;

    //any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);//converts unsigned int hostlong from host byte order to network byte order (host order is computer dependant)
    remote.sin_port = htons(clientPort);//local port | converts unsigned short int hostshot from host byte order to network byre order (network order is big endian sig bits on RHS)

    iRetval = bind(hSocket, (struct sockaddr *) &remote, sizeof(remote));

    return iRetval;

}

int main(int argc, char *argv[]){
    int socket_desc = 0, sock=0, clientLen = 0;
    struct sockaddr_in client;
    //QUESTION - if the size is small i get zsh: illegal hardware instruction 
    char client_message[200] = {0};
    char message[200] = {0};
    int recievedNumber = 0, sentNumber = 0;

    //create socket
    socket_desc = socketCreate();
    if (socket_desc==-1){
        perror("bind failed");
        return -1;
    }
    printf("Socket created\n");

    //bind 
    if (bindCreatedSocket(socket_desc)<0){
        perror("bind failed");
        return 1;
    }
    printf("Bind done\n");

    //listen (max connections)
    listen(socket_desc, 3);

    //accept incoming connection
    while(1){
        printf("Waiting for incoming connections...\n");
        clientLen = sizeof(struct sockaddr_in);

        //accept connection (blocked until recieves connection)
        sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t*)&clientLen);

        if (sock <0){
            perror("accept failed");
            return 1;
        }
        printf("Connection accepted");

        memset(client_message, '\0', sizeof(client_message));
        memset(message, '\0', sizeof(message));

        //recieve reply from client
        if (recv(sock, client_message, 200, 0)<0){
            printf("recv failed");
            break;
        }

        printf("Client reply: %s\n", client_message);


        close(sock);

        printf("Waiting for incoming connections...\n");
        clientLen = sizeof(struct sockaddr_in);

        //accept connection (blocked until recieves connection)
        sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t*)&clientLen);

        if (sock <0){
            perror("accept failed");
            return 1;
        }
        printf("Connection accepted");

        memset(client_message, '\0', sizeof(client_message));
        memset(message, '\0', sizeof(message));

        //send data to client 2
        if (send(sock, message, strlen(message),0)<0){
            printf("Send failed");
            return 1;
        }


        close(sock);
        sleep(1);

    }



    








}