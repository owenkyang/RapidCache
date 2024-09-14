#include <stdio.h>      // For printf
#include <stdlib.h>     // For exit
#include <string.h>     // For memset
#include <arpa/inet.h>  // For sockaddr_in and inet_addr
#include <sys/socket.h> // For socket functions
#include <unistd.h> 
int main(){
    int fd = socket(AF_INET, SOCK_STREAM, 0);
}

