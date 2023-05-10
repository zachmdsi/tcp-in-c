#include "server.h"
#include <stdio.h>
#include <unistd.h>

int main() {
    int server_sock = start_server(12345);
    if (server_sock == -1) {
        perror("Failed to start server");
        return 1;
    }

    printf("Server started, waiting for connections...\n");

    close(server_sock);
    return 0;
}