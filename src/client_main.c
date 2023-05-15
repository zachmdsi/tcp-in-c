#include <stdio.h>
#include "client.h"

int main() {
    int client_sock = start_client("127.0.0.1", 8080);
    if (client_sock == -1) {
        perror("Error starting the client");
        return -1;
    }

    const char *message = "Hello, Server!";
    if (send(client_sock, message, strlen(message), 0) == -1) {
        perror("Error sending message");
    }

    close(client_sock);

    return 0;
}