#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>

void error_handle(const char* s) {
    perror(s);
    exit(1);
}

int main(int argc, char* argv[]) {

    sockaddr_in server_addr, clnt_addr;
    socklen_t clnt_addr_size;
    int serv_sockfd;
    int clnt_sockfd;
    char message[] = "Hello world";

    if(argc != 2) {
        fprintf(stderr, "Usage :  %s <port> ", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    serv_sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sockfd == -1) {
        error_handle("socket()");
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_family = AF_INET;

    if(bind(serv_sockfd, (sockaddr*)&server_addr, sizeof(sockaddr)) == -1) {
        error_handle("bind()");
    }

    if(listen(serv_sockfd, 5) == -1) {
        error_handle("listen()");
    }   

    clnt_addr_size = sizeof(clnt_addr);
    clnt_sockfd = accept(serv_sockfd, (sockaddr*)&clnt_addr, &clnt_addr_size);
    if(clnt_sockfd == -1) {
        error_handle("accept()");
    }
    write(clnt_sockfd, message, sizeof(message));
}

