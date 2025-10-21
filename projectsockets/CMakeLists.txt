cmake_minimum_required(VERSION 3.20)
project(ws_echo CXX)

add_executable(ws_server ws_server.cpp)
add_executable(ws_client ws_client.cpp)

# Link Winsock for MinGW or MSVC
target_link_libraries(ws_server PRIVATE ws2_32)
target_link_libraries(ws_client PRIVATE ws2_32)
