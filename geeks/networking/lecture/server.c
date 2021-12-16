/*
steps:
    - create new socket for network communication
    - attach local address to socket (bind)
    - announce willingness to accept connections (listen)
    - block caller until a connection request arrives (accept)
    - actively attempt to establish a connection (connect)
    - send some data over connection (send)
    - receive some data over connection (receieve)
    - release the connection (close)

server:
    - create socket with socket() system call
    - bind socket to an address using bind() system call
        - for a server socket on internet address consists of port number on host machine
    - listen for connections with listen()
    - accept connection with accept() system call
        - blocks connection until a client connects with server
    - send/recieve data using read()/recv and write()/send 
*/

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
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_port = htons(clientPort);//local port

    iRetval = bind(hSocket, (struct sockaddr *) &remote, sizeof(remote));

    return iRetval;

}

int main(int argc, char *argv[]){
    int socket_desc = 0, sock=0, clientLen = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const char *pMessage = "Hello to C Server\n";

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

        //can use bzero
        memset(client_message, '\0', sizeof(client_message));
        memset(message, '\0', sizeof(message));

        //recieve reply from client
        if (recv(sock, client_message, 200, 0)<0){
            printf("recv failed");
            break;
        }

        printf("Client reply: %s\n", client_message);

        if(strcmp(pMessage,client_message)==0){
            strcpy(message,"Hello");
        }else{
            strcpy(message,"Invalid");
        }

        //send data
        if (send(sock, message, strlen(message),0)<0){
            printf("Send failed");
            return 1;
        }


        close(sock);
        sleep(1);

    }



    








}