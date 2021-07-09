#include "Connection.h"

#ifdef _WIN32
int inet_pton(int af, const char *src, void *dst)
{
    struct sockaddr_storage ss;
    int size = sizeof(ss);
    char src_copy[INET6_ADDRSTRLEN + 1];
    ZeroMemory(&ss, sizeof(ss));
    strncpy(src_copy, src, INET6_ADDRSTRLEN + 1);
    src_copy[INET6_ADDRSTRLEN] = 0;

    if (WSAStringToAddress((LPWSTR)src_copy, af, NULL, (struct sockaddr *)&ss, &size) == 0)
        switch (af)
        {
        case AF_INET:
            *(struct in_addr *)dst = ((struct sockaddr_in *)&ss)->sin_addr;
            return 1;
        case AF_INET6:
            *(struct in6_addr *)dst = ((struct sockaddr_in6 *)&ss)->sin6_addr;
            return 1;
        }
    return 0;
}
#endif

std::string DC1[] = {"149.154.175.53", "2001:b28:f23d:f001::a"};
std::string DC2[] = {"149.154.167.51", "2001:67c:4e8:f002::a"};
std::string DC3[] = {"149.154.175.100", "2001:b28:f23d:f003::a"};
std::string DC4[] = {"149.154.167.91", "2001:67c:4e8:f004::a"};
std::string DC5[] = {"91.108.56.130", "2001:b28:f23f:f005::a"};

Connection::Connection(std::string dc[2], int port, bool use_ipv6)
{
    std::string address = dc[use_ipv6 ? 1 : 0];
    __server_address.sin_family = use_ipv6 ? AF_INET6 : AF_INET;
    __sockfd = socket(__server_address.sin_family, SOCK_STREAM, 0);

    if (__sockfd == -1)
        throw std::runtime_error("Can't initialize the connection: " + std::string(strerror(errno)));
    __server_address.sin_port = htons(port);

    if (inet_pton(AF_INET, address.c_str(), &__server_address.sin_addr) <= 0)
        throw std::runtime_error("Invalid address: " + std::string(address));
}

void Connection::start()
{
    if (__is_started)
        throw std::runtime_error("The connection has already been started");

    if (connect(__sockfd, (struct sockaddr *)&__server_address, sizeof(__server_address)) < 0)
        throw std::runtime_error("Can't start the connection: " + std::string(strerror(errno)));
    __is_started = true;
}

std::string Connection::recv(size_t length)
{
    size_t total_recv = 0;
    std::vector<char> buffer(length);

    do
    {
        size_t chunk_recv = ::recv(__sockfd, buffer.data() + total_recv, length - total_recv, 0);

        if (chunk_recv <= 0)
            throw std::runtime_error(strerror(errno));
        total_recv += chunk_recv;
    } while (length < total_recv);
    return std::string(buffer.data());
}

void Connection::send(std::string buffer)
{
    if (::send(__sockfd, buffer.data(), buffer.length(), 0) <= 0)
        throw std::runtime_error(strerror(errno));
}

void Connection::stop()
{
    if (!__is_started)
        throw std::runtime_error("The connection has not been started yet");

#ifdef _WIN32
    if (closesocket(__sockfd) < 0)
        throw std::runtime_error("Can't close the connection: " + std::string(strerror(errno)));
#else
    if (close(__sockfd) < 0)
        throw std::runtime_error("Can't close the connection: " + std::string(strerror(errno)));
#endif
    __is_started = false;
}

Connection::~Connection()
{
    if (__is_started)
        stop();
}
