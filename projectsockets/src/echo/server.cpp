// Windows Echo Server (Winsock2)
// build via CMake; links to Ws2_32.lib

#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib") // harmless if also linked via CMake

static void die(const char* where) {
    std::cerr << where << " failed, WSAGetLastError=" << WSAGetLastError() << "\n";
    std::exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    int port = 8080;
    if (argc >= 2) port = std::stoi(argv[1]);

    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) die("WSAStartup");

    SOCKET sfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sfd == INVALID_SOCKET) die("socket");

    // reuse addr
    BOOL opt = TRUE;
    if (setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, (const char*)&opt, sizeof(opt)) == SOCKET_ERROR)
        die("setsockopt");

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(static_cast<u_short>(port));

    if (bind(sfd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == SOCKET_ERROR)
        die("bind");

    if (listen(sfd, SOMAXCONN) == SOCKET_ERROR)
        die("listen");

    std::cout << "[server] listening on port " << port << " …\n";

    for (;;) {
        sockaddr_in cli{};
        int len = sizeof(cli);
        SOCKET cfd = accept(sfd, reinterpret_cast<sockaddr*>(&cli), &len);
        if (cfd == INVALID_SOCKET) {
            std::cerr << "accept error: " << WSAGetLastError() << "\n";
            continue;
        }

        char ip[INET_ADDRSTRLEN] = {0};
        inet_ntop(AF_INET, &cli.sin_addr, ip, sizeof(ip));
        std::cout << "[server] client connected: " << ip << ":" << ntohs(cli.sin_port) << "\n";

        char buf[4096];
        for (;;) {
            int n = recv(cfd, buf, sizeof(buf), 0);
            if (n == 0) {
                std::cout << "[server] client closed\n";
                break;
            }
            if (n == SOCKET_ERROR) {
                std::cerr << "recv error: " << WSAGetLastError() << "\n";
                break;
            }
            int sent = 0;
            while (sent < n) {
                int m = send(cfd, buf + sent, n - sent, 0);
                if (m == SOCKET_ERROR) {
                    std::cerr << "send error: " << WSAGetLastError() << "\n";
                    break;
                }
                sent += m;
            }
        }

        shutdown(cfd, SD_BOTH);
        closesocket(cfd);
    }

    closesocket(sfd);
    WSACleanup();
    return 0;
}
