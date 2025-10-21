// Windows Echo Client (Winsock2)
// build via CMake; links to Ws2_32.lib

// ws_client.cpp
// Build (Developer Command Prompt): cl ws_client.cpp /EHsc ws2_32.lib
// ws_server.cpp
// Build: cl ws_server.cpp /EHsc ws2_32.lib

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>

#pragma comment(lib, "ws2_32.lib")  // Links the Winsock library automatically


int main() {
    // 1) Initialize Winsock
    WSADATA wsa{};
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        std::cerr << "WSAStartup failed\n";
        return 1;
    }

    // 2) Resolve server (localhost:9000)
    const char* host = "127.0.0.1";
    const char* port = "9000";
    addrinfo hints{}; hints.ai_family = AF_UNSPEC; hints.ai_socktype = SOCK_STREAM;
    addrinfo* res = nullptr;
    int err = getaddrinfo(host, port, &hints, &res);
    if (err != 0) { std::cerr << "getaddrinfo: " << gai_strerrorA(err) << "\n"; WSACleanup(); return 1; }

    // 3) Create & connect
    SOCKET s = INVALID_SOCKET;
    for (addrinfo* ai = res; ai; ai = ai->ai_next) {
        s = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
        if (s == INVALID_SOCKET) continue;
        if (connect(s, ai->ai_addr, (int)ai->ai_addrlen) == 0) break;
        closesocket(s); s = INVALID_SOCKET;
    }
    freeaddrinfo(res);
    if (s == INVALID_SOCKET) { std::cerr << "connect failed\n"; WSACleanup(); return 1; }

    // 4) Send a line, receive echo, print
    std::string line = "Hello from Windows client!\r\n";
    int to_send = (int)line.size(), sent = 0;
    while (sent < to_send) {
        int n = send(s, line.data() + sent, to_send - sent, 0);
        if (n <= 0) { std::cerr << "send error: " << WSAGetLastError() << "\n"; closesocket(s); WSACleanup(); return 1; }
        sent += n;
    }

    char buf[1024];
    int n = recv(s, buf, sizeof(buf)-1, 0);
    if (n > 0) { buf[n] = 0; std::cout << "Server replied: " << buf; }

    // 5) Shutdown & cleanup
    shutdown(s, SD_SEND);
    closesocket(s);
    WSACleanup();
    return 0;
}
