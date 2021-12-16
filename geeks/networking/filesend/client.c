/*
client
    - create socket using socket()
    - connect socket to address of serer using connect()
    - send and receive data
        - simplest way using read/recv and write/send




*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


//create socket for server communication
short socketCreate(void){
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}


//try to connect with server
int socketConnect(int hSocket){
    int iRetval = -1;
    int ServerPort = 12345;

    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);

    iRetval = connect(hSocket, (struct sockaddr *) &remote, sizeof(remote));

    return iRetval;
}

//send data to server and set timeout of 20 seconds
int socketSend(int hSocket, char* Rqst, short lenRqst ){
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv))<0){
        printf("time out\n");
        return -1;
    }

    shortRetval = send(hSocket, Rqst, lenRqst,0);
    return shortRetval;
}


int socketReceive(int hSocket, char* Rsp, short lenRsp ){
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv))<0){
        printf("time out\n");
        return -1;
    }

    shortRetval = recv(hSocket, Rsp, lenRsp,0);
    return shortRetval;
}

int main(){
    printf("Hi\n");
    int hSocket = 0, read_size=0;
    struct sockaddr_in server;
    char serverReply[200] = {0};
    char sendToServer[100] = {0};

    hSocket = socketCreate();

    if (hSocket==-1){
        printf("Could not create socket\n");
        return 1;
    }
    printf("Socket is created\n");

    //connect to server
    if (socketConnect(hSocket)<0){
        perror("connect failed\n");
        return 1;
    }
    printf("Successfully connected with server \n");


    //grab user message 
    printf("Enter the message: ");
    fgets(sendToServer, 100, stdin);

    //send data to server
    socketSend(hSocket, sendToServer, strlen(sendToServer));

    //recieve data from server
    read_size = socketReceive(hSocket, serverReply, 200);
    printf("Server response: %s\n\n", serverReply);
    
    close(hSocket);
    
    return 0;


}