#pragma once
#include <stdexcept>
#include <string>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>

int inet_pton(int af, const char *src, void *dst);
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#endif
#include <vector>

extern std::string DC1[2];
extern std::string DC2[2];
extern std::string DC3[2];
extern std::string DC4[2];
extern std::string DC5[2];

class Connection
{
private:
    bool __is_started = false;
    struct sockaddr_in __server_address;
    int __sockfd;

public:
    Connection(std::string dc[2] = DC4, int port = 80, bool use_ipv6 = false);
    void start();
    std::string recv(size_t len);
    void send(std::string buf);
    void stop();
    ~Connection();
};
