#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include "client.h"

int start_client(const char* server_ip, int port) {
    // create a socket
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        return -1;
    }

    // specify server's details
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, server_ip, &(server_addr.sin_addr)) <= 0){
        return -1;
    }

    // connect to the server
    if (connect(client_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        close(client_sock);
        return -1;
    }

    // send a message to the server
    const char* message = "Hello, server!";
    send(client_sock, message, strlen(message), 0);

    return client_sock;
}
