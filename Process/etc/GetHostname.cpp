#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

// Winsock 라이브러리를 초기화하고 종료하기 위한 라이브러리 링크
#pragma comment(lib, "Ws2_32.lib")

int main() {
    WSADATA wsaData;

    // Winsock을 초기화합니다.
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    // 호스트 이름을 저장할 버퍼
    char host_name[256];

    // gethostname을 사용하여 호스트 이름을 가져옵니다.
    if (gethostname(host_name, sizeof(host_name)) == SOCKET_ERROR) {
        std::cerr << "Error getting hostname: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    std::cout << "Hostname: " << host_name << std::endl;

    // 호스트 이름을 기반으로 addrinfo 구조체를 가져옵니다.
    addrinfo hints = { 0 }, * res = nullptr;
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // getaddrinfo를 사용하여 IP 주소를 가져옵니다.
    if (getaddrinfo(host_name, nullptr, &hints, &res) != 0) {
        std::cerr << "getaddrinfo failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // 가져온 IP 주소를 출력합니다.
    for (addrinfo* ptr = res; ptr != nullptr; ptr = ptr->ai_next) {
        sockaddr_in* sockaddr_ipv4 = reinterpret_cast<sockaddr_in*>(ptr->ai_addr);
        char ip_str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(sockaddr_ipv4->sin_addr), ip_str, INET_ADDRSTRLEN);
        std::cout << "IP Address: " << ip_str << std::endl;
    }

    // 메모리 해제
    freeaddrinfo(res);

    // Winsock을 종료합니다.
    WSACleanup();

    return 0;
}
