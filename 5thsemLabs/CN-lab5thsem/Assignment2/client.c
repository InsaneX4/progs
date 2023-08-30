#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

int main() {
#ifdef _WIN32
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to initialize Winsock.\n");
        return 1;
    }
#endif

    int sockFd, bs;
    sockFd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in x;
    x.sin_family = AF_INET;
    x.sin_port = htons(6009);
    x.sin_addr.s_addr = inet_addr("127.0.0.1");

    bs = bind(sockFd, (struct sockaddr *)&x, sizeof(x));
    char msg[100];
    printf("Enter the text:\n");
    scanf("%[^\n]%*c", msg);

    printf("Sending text...\n");
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(6011);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(sockFd, msg, sizeof(msg), 0, (struct sockaddr *)&server, sizeof(struct sockaddr));
    printf("Message Sent.\n");

#ifdef _WIN32
    // Cleanup Winsock
    WSACleanup();
#endif

    return 0;
}
