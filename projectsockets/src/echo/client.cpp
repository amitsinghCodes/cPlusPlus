// Windows Echo Client (Winsock2)
// build via CMake; links to Ws2_32.lib

#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>

#pragma comment(lib, "Ws2_32.lib")

static void die(const char* where) {
    std::cerr << where << " failed, WSAGetLastError=" << WSAGetLastError() << "\n";
    std::exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    std::string host = "127.0.0.1";
    int port = 8080;
    if (argc >= 2) host = argv[1];
    if (argc >= 3) port = std::stoi(argv[2]);

    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) die("WSAStartup");

    SOCKET cfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (cfd == INVALID_SOCKET) die("socket");

    addrinfo hints{};
    hints.ai_family   = AF_INET;      // IPv4
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    addrinfo* res = nullptr;
    std::string portStr = std::to_string(port);
    if (getaddrinfo(host.c_str(), portStr.c_str(), &hints, &res) != 0)
        die("getaddrinfo");

    if (connect(cfd, res->ai_addr, (int)res->ai_addrlen) == SOCKET_ERROR)
        die("connect");

    freeaddrinfo(res);

    std::cout << "[client] connected to " << host << ":" << port << "\n";
    std::cout << "Type lines and press Enter. Ctrl+C to quit.\n";

    std::atomic<bool> running{true};

    // receive thread
    std::thread rx([&] {
        char buf[4096];
        while (running.load()) {
            int n = recv(cfd, buf, sizeof(buf), 0);
            if (n == 0) {
                std::cout << "\n[client] server closed connection\n";
                running.store(false);
                break;
            }
            if (n == SOCKET_ERROR) {
                std::cerr << "[client] recv error: " << WSAGetLastError() << "\n";
                running.store(false);
                break;
            }
            std::cout.write(buf, n);
            std::cout.flush();
        }
    });

    // stdin -> socket
    std::string line;
    while (running.load() && std::getline(std::cin, line)) {
        line.push_back('\n');
        const char* p = line.data();
        int left = static_cast<int>(line.size());
        while (left > 0) {
            int n = send(cfd, p, left, 0);
            if (n == SOCKET_ERROR) {
                std::cerr << "[client] send error: " << WSAGetLastError() << "\n";
                running.store(false);
                break;
            }
            p += n;
            left -= n;
        }
    }

    running.store(false);
    shutdown(cfd, SD_BOTH);
    closesocket(cfd);
    if (rx.joinable()) rx.join();

    WSACleanup();
    return 0;
}
