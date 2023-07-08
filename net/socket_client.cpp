#include <cstddef>
#include <sys/epoll.h>
#include <unistd.h>
#include <sys/socket.h>
#include <cstdio>
#include <fcntl.h>
#include <netinet/in.h>
#include <cstdlib>
#include <arpa/inet.h>
#include <cstring>

void error_handle(const char* s) {
    perror(s);
    exit(1);
}


int main(int argc, char* argv[]) {

    int sockfd;
    sockaddr_in server_addr;
    char message[30];
    int str_len = 0;
    if(argc != 3) {
        fprintf(stderr, "Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sockfd, (sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handle("connect()");
    }

    read(sockfd, message, sizeof(message));

    printf("message from server :\n%s", message);

}
