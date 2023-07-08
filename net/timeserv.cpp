#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctime>

void error_handle(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {

    if(argc != 2) {
        fprintf(stderr, "Usage %s <ip>", argv[0]);
        exit(1);
    }

    int serv_sock, clnt_sock;
    sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;
    const char* ip = argv[1];
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(ip));

    serv_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(serv_sock == -1)
        error_handle("socket()");

    if(bind(serv_sock, (sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) 
        error_handle("bind()");

    if(listen(serv_sock, 10) == -1) 
        error_handle("listen()");
    
    char message[30];

    while(true) {
        memset(message, 0, sizeof(message));
        time_t times;
        times = time(NULL);
        memset(&clnt_addr, 0, sizeof(clnt_addr));
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (sockaddr*)&clnt_addr, &clnt_addr_size);
        if(clnt_sock == -1) 
            error_handle("accept()");
        // char addr[20];
        // memset(&addr, 0, sizeof(addr));
        // sprintf(addr, "%d", clnt_addr.sin_addr.s_addr);
        
        char dst[50];
        fprintf(stdout, "Time : %s Receive from %s %u\n", ctime(&times), inet_ntop(AF_INET, &clnt_addr.sin_addr, dst, sizeof(clnt_addr)), ntohs(clnt_addr.sin_port));
        read(clnt_sock, message, sizeof(message));
        fprintf(stdout, "message : %s", message);
    }
}