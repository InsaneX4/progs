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

    int sockfD, m;
    struct sockaddr_in server_addr, client_addr;
    sockfD = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfD == -1) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(6011);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfD, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    printf("Server is running and waiting for messages...\n");

    while (1) { // Infinite loop to keep the server running
        char buf[100];
        int len = sizeof(client_addr);
        m = recvfrom(sockfD, buf, sizeof(buf), 0, (struct sockaddr *)&client_addr, &len);
        if (m == -1) {
            perror("recvfrom");
            return 1;
        }

        printf("Received from Client: %s\n", buf);
    }

#ifdef _WIN32
    // Cleanup Winsock
    WSACleanup();
#endif

    return 0;
}
