#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <cstring>

void error_handle(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {

    if(argc != 2) {
        fprintf(stderr, "Usage : %s <port>", argv[0]);
        exit(1);
    }

    const char* ip = argv[1];

    sockaddr_in serv_addr, clnt_addr;
    int serv_sock, clnt_sock;
    socklen_t clnt_addr_size;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(ip));
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    serv_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(serv_sock == -1) {
        error_handle("socket");
    }

    if(bind(serv_sock, (sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handle("bind()");
    }
    //! listen(fd, backlog), backlog 代表 TCP半连接缓存大小，backlog 与 TCP的半缓存攻击有关 
    if(listen(serv_sock, 10) == -1) {
        error_handle("listen()");
    }
    memset(&clnt_addr, 0, sizeof(clnt_addr));
    clnt_addr_size = sizeof(clnt_addr);
    
    clnt_sock = accept(serv_sock, (sockaddr*)&clnt_addr, &clnt_addr_size);

    if(clnt_sock == -1) 
        error_handle("accept()");


    int epollfd = epoll_create(10);
    if(epollfd == -1) 
        error_handle("epoll_create()");

    epoll_event event;
    event.events |= EPOLLIN;
    char  str[] = "1234";
    event.data.ptr = static_cast<void*>(str);

    epoll_ctl(epollfd, EPOLL_CTL_ADD, clnt_sock, &event);

    epoll_wait(epollfd, &event, 10, 10000);
}