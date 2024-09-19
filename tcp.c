#include <stdio.h>      // For printf
#include <stdlib.h>     // For exit
#include <string.h>     // For memset
#include <arpa/inet.h>  // For sockaddr_in and inet_addr
#include <sys/socket.h> // For socket functions
#include <unistd.h> 
#include <stdbool.h>
int main(){
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    int val = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

    struct sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = ntohs(1234);
    addr.sin_addr.s_addr = ntohl(0);
    int rv = bind(fd, (const struct sockaddr *)&addr, sizeof(addr));
    if (rv) {
        die("bind()");
    }
    rv = listen(fd, SOMAXCONN);
    if (rv){
        die("listen()");
    }
    while (true) {
        struct sockaddr_in client_addr = {};
        socklen_t addrlen = sizeof(client_addr);
        int connfd = accept(fd, (struct sockaddr *)&client_addr, &addrlen);
        if (connfd < 0){
            continue;
        }
        close(connfd);
    }
}

