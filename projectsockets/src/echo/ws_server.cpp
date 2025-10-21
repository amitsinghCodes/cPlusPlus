// Windows Echo Server (Winsock2)
// build via CMake; links to Ws2_32.lib

// ws_server.cpp
// Build (Developer Command Prompt): cl ws_server.cpp /EHsc ws2_32.lib
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

    // 2) Create listening socket (IPv4/TCP)
    SOCKET s_listen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s_listen == INVALID_SOCKET) { std::cerr << "socket failed\n"; WSACleanup(); return 1; }

    // 3) Allow quick rebinding
    BOOL yes = TRUE;
    setsockopt(s_listen, SOL_SOCKET, SO_REUSEADDR, (const char*)&yes, sizeof(yes));

    // 4) Bind to 0.0.0.0:9000
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(9000);
    if (bind(s_listen, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
        std::cerr << "bind failed: " << WSAGetLastError() << "\n";
        closesocket(s_listen); WSACleanup(); return 1;
    }

    // 5) Listen
    if (listen(s_listen, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "listen failed: " << WSAGetLastError() << "\n";
        closesocket(s_listen); WSACleanup(); return 1;
    }
    std::cout << "Server listening on 0.0.0.0:9000\n";

    // 6) Accept one client (keep it super simple)
    sockaddr_in cli{}; int cliLen = sizeof(cli);
    SOCKET s_client = accept(s_listen, (sockaddr*)&cli, &cliLen);
    if (s_client == INVALID_SOCKET) {
        std::cerr << "accept failed: " << WSAGetLastError() << "\n";
        closesocket(s_listen); WSACleanup(); return 1;
    }

    // 7) Echo loop
    char buf[1024];
    for (;;) {
        int n = recv(s_client, buf, sizeof(buf), 0);
        if (n == 0) { std::cout << "client closed\n"; break; }
        if (n < 0)  { std::cerr << "recv error: " << WSAGetLastError() << "\n"; break; }

        int sent = 0;
        while (sent < n) {
            int m = send(s_client, buf + sent, n - sent, 0);
            if (m <= 0) { std::cerr << "send error: " << WSAGetLastError() << "\n"; goto done; }
            sent += m;
        }
    }

done:
    // 8) Shutdown & cleanup
    shutdown(s_client, SD_SEND);
    closesocket(s_client);
    closesocket(s_listen);
    WSACleanup();
    return 0;
}
