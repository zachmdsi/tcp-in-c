#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include "server.h"

#define BUFFER_SIZE 1024

int main() {
    int server_sock = start_server(8080);
    if (server_sock == -1) {
        perror("Failed to start server");
        return 1;
    }

    printf("Server started. Waiting for connections...\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        int client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_len);
        if (client_sock == -1) {
            perror("Error accepting connection");
            continue;
        }

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            perror("Error receiving data");
        } else {
            printf("Received message: %s\n", buffer);
        }

        close(client_sock);
    } 

    return 0;
}