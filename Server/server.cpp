#include <WinSock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <bits/stdc++.h>

int wmain(void)
{
    printf("Starting Server Services\n");
    WSAData Data;
    WSAStartup(MAKEWORD(2, 2), &Data);
    SOCKET Server = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in address;
    address.sin_addr.s_addr = 0;
    address.sin_family = AF_INET6;
    address.sin_port = htons(8080);

    bind(Server, (sockaddr *)&address, sizeof(address));

    printf("Server Started\n");

    listen(Server, SOMAXCONN);

    SOCKET Client = accept(Server, 0, 0);
    char request[1024] = {0};
    recv(Client, request, 1024, 0);
    send(Client, "done", 1024, 0);
    printf("%s\n", request);
}