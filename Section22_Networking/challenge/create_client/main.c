#include <stdio.h>
#include <stdlib.h> // for exit()
#include <errno.h>
#include <string.h>
#include <unistd.h>     // sleep
#include <netdb.h>      // getservbyname() getservbyport()
#include <sys/socket.h> // socket() bind() listen() accept() recv() send()
#include <arpa/inet.h>  // iner_addr()

int SocketCreate()
{
    int socketFd;
    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        fprintf(stderr, "socket() error=%d (%s)\n", errno, strerror(errno));
        return -1;
    }
    printf("Socket %d created\n", socketFd);
    return socketFd;
}

void Connect(int socketFd, int serverPort)
{
    // fill server socket addr
    struct sockaddr_in remote = {0};
    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); // local host IP address (string to integer)
    remote.sin_port = htons(serverPort);

    // connect to the server
    if (connect(socketFd, (struct sockaddr *)&remote, sizeof(struct sockaddr_in)) == -1)
    {
        fprintf(stderr, "connect() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
}

void SocketSend(int socketFd, char *msg, int msgLen)
{
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    // set options
    if (setsockopt(socketFd, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) == -1)
    {
        fprintf(stderr, "setsockopt() error=%d (%s)\n", errno, strerror(errno));
        return;
    }

    // send data
    int sentSize = send(socketFd, msg, msgLen, 0);
    if (sentSize == -1)
    {
        fprintf(stderr, "send() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    printf("message sent\n");
}

void SocketReceive(int socketFd, char *msg, int msgLen)
{
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    // set options
    if (setsockopt(socketFd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) == -1)
    {
        fprintf(stderr, "setsockopt() error=%d (%s)\n", errno, strerror(errno));
        return;
    }

    // send data
    int rcvSize = recv(socketFd, msg, msgLen, 0);
    if (rcvSize == -1)
    {
        fprintf(stderr, "recv() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    printf("message received size=%d, message=%s\n", rcvSize, msg);
}

int main()
{
    int clientSockFd = SocketCreate();
    char inBuf[200] = {0};
    char outBuf[200] = {0};
    Connect(clientSockFd, 12345);
    while (1)
    {
        printf("Enter the number to send: ");
        // block
        scanf("%s", outBuf);
        printf("You entered: %s\n", outBuf);
        SocketSend(clientSockFd, outBuf, strlen(outBuf));
        // check for exit
        if (!strcmp(outBuf, "exit"))
            break;
        // receive
        memset(inBuf, 0, sizeof(inBuf));
        // block
        SocketReceive(clientSockFd, inBuf, sizeof(inBuf));
        // sleep(1);
    }

    close(clientSockFd);

    return 0;
};
