#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

int start_server(int port) {
    // create a socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        return -1;
    }
    
    // set socket options (optional)
    int opt = 1;
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        close(server_sock);
        return -1;
    }

    // bind to a port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // listen for connections
    if (listen(server_sock, SOMAXCONN) == -1) {
        close(server_sock);
        return -1;
    }

    return server_sock;
}