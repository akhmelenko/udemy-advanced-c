#include <stdio.h>
#include <stdlib.h> // for exit()
#include <errno.h>
#include <string.h>
#include <unistd.h>     // sleep
#include <netdb.h>      // getservbyname() getservbyport()
#include <sys/socket.h> // socket() bind() listen() accept() recv() send()
#include <arpa/inet.h>  // inet_ntoa()
#include <pthread.h>

int SocketCreate()
{
    int hSocket;
    if ((hSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        fprintf(stderr, "socket() error=%d (%s)\n", errno, strerror(errno));
        return -1;
    }
    printf("Socket %d created\n", hSocket);
    return hSocket;
}

void SocketBind(int hSocket, int clientPort)
{
    struct sockaddr_in sockAddrIn = {0};
    // Internet address family
    sockAddrIn.sin_family = AF_INET;
    // any incoming interface (127.0.0.0)
    sockAddrIn.sin_addr.s_addr = htonl(INADDR_ANY);
    // local port
    sockAddrIn.sin_port = htons(clientPort);

    if (bind(hSocket, (struct sockaddr *)&sockAddrIn, sizeof(sockAddrIn)) == -1)
    {
        fprintf(stderr, "bind() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    printf("bind done\n");
}

#define LISTEN_QUEUE_DEPTH 1 // max client number to connect

void *ServerThreadHandler(void *_clientSocket)
{
    int clientSocket = *(int *)_clientSocket;
    struct sockaddr_in addr;
    socklen_t addr_size = sizeof(struct sockaddr_in);
    int res = getpeername(clientSocket, (struct sockaddr *)&addr, &addr_size);
    char clientip[20] = {0};
    strcpy(clientip, inet_ntoa(addr.sin_addr));

    printf("Connection accepted for IP=%s port=%d\n", clientip, addr.sin_port);
    // clean input message buf
    char inBuf[200];
    memset(inBuf, 0, sizeof(inBuf));

    // if (state == 0)
    while (1)
    {
        // receive from client
        memset(inBuf, 0, sizeof(inBuf));
        int rcvSize = recv(clientSocket, inBuf, sizeof(inBuf), 0);
        if (rcvSize == -1)
        {
            fprintf(stderr, "recv() error=%d (%s)\n", errno, strerror(errno));
            return NULL;
        }
        // check for exit
        if (!strcmp(inBuf, "exit"))
        {
            printf("Connection closed for IP=%s port=%d\n", clientip, addr.sin_port);
            break;
        }
        printf("received message size=%d, message: %s\n", rcvSize, inBuf);
        int number = atoi(inBuf);

        char outBuf[200];
        sprintf(outBuf, "%d", number + 1);
        int sentSize = send(clientSocket, outBuf, strlen(outBuf), 0);
        if (sentSize == -1)
        {
            fprintf(stderr, "send() error=%d (%s)\n", errno, strerror(errno));
            return NULL;
        }
        printf("sent message with %d bytes\n", sentSize);
    }
    // close client connection
    close(clientSocket);
    // free allocated memory
    free(_clientSocket);
}

int main()
{
    int serverSockFd = SocketCreate();
    SocketBind(serverSockFd, 12345);

    // start listen with queue size
    if (listen(serverSockFd, LISTEN_QUEUE_DEPTH) == -1)
    {
        fprintf(stderr, "listen() error=%d (%s)\n", errno, strerror(errno));
        return -1;
    }

    struct sockaddr_in clientSockAddr;
    int clientAddrLen = sizeof(clientSockAddr);

    while (1)
    {
        printf("waiting for incoming connections\n");
        // accept incoming connection
        int cliSocket =    (serverSockFd, (struct sockaddr *)&clientSockAddr, (socklen_t *)&clientAddrLen);
        if (cliSocket == -1)
        {
            fprintf(stderr, "accept() error=%d (%s)\n", errno, strerror(errno));
            return -1;
        }
        int *newSocket = (int *)malloc(sizeof(int));
        *newSocket = cliSocket;
        pthread_t pid;
        pthread_create(&pid, NULL, ServerThreadHandler, (void *)newSocket);
    }
    return 0;
};
