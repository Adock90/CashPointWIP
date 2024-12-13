#define __MON_LOGIC__

#define _C_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <WinSock2.h>

typedef int NumID;
typedef char* NumString;

enum IDS
{
	MONEY_INVALID = 0,
	MONEY_VALID = 1
};

NumID checkSum(NumID MonSub, NumID AccountNum)
{
	int Result = AccountNum - MonSub;
	
	if (Result >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Send(NumString UserName, NumID UserAccount, NumID MoneySend, NumString to)
{
	char DataArray[1024];

	sprintf_s(DataArray, "%s, %d, %s", UserName, MoneySend, to);

	int Sending = SendDataToServer(DataArray);
	int res;
	switch (Sending)
	{
	case MONEY_INVALID:
		MessageBox(0, L"Could Not establish Connection to Server", L"Opps", MB_ICONERROR | MB_OK);
		res = 0;
		break;
	default:
		res = 1;
		break;
	}
	return res;
}

int SendDataToServer(char Data[])
{
	int res;

	WSADATA data;

	WSAStartup(MAKEWORD(2, 2), &data);

	SOCKET ClientSock = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);

	struct sockaddr_in ServerAddress;
	ServerAddress.sin_addr.s_addr = inet_pton("127.0.0.1");
	ServerAddress.sin_family = AF_INET6;
	ServerAddress.sin_port = htons(8080);

	int Connection = connect(ClientSock, (struct sockaddr*)&ServerAddress, sizeof(ServerAddress));
	switch (Connection)
	{
	case SOCKET_ERROR:
		MessageBox(0, L"Socket Error", L"Opps", MB_ICONERROR | MB_OK);
		closesocket(ClientSock);
		WSACleanup();
		res = 0;
		exit(-1);
		break;
	default:
		break;
	}

	int connectSend = send(ClientSock, Data, 1024, 0);
	switch (connectSend)
	{
	case SOCKET_ERROR:
		MessageBox(0, L"Socket Error", L"Opps", MB_ICONERROR | MB_OK);
		closesocket(ClientSock);
		WSACleanup();
		res = 0;
		exit(-1);
		break;
	default:
		break;
	}
	int NoMoreSending = shutdown(ClientSock, SD_SEND);
	switch (NoMoreSending)
	{
	case SOCKET_ERROR:
		MessageBox(0, L"Socket Error", L"Opps", MB_ICONERROR | MB_OK);
		closesocket(ClientSock);
		WSACleanup();
		res = 0;
		exit(-1);
		break;
	default:
		break;
	}
	int Waiting = 1;
	char buff[1024] = { 0 };
	while (Waiting > 0)
	{
		Waiting = recv(ClientSock, buff, 1024, 0);
		if (Waiting > 0)
		{
			wprintf(L"Done\n");
		}
		else if (Waiting == 0)
		{
			wprintf(L"Closed Connection\n");
		}
		else
		{
			wprintf(L"Error");
		}
		if (memcmp(buff, "done", 4) == 0)
		{
			res = 1;
		}
		else
		{
			res = 0;
		}
	}
	int StoppingServices = closesocket(ClientSock);
	if (StoppingServices == SOCKET_ERROR)
	{
		MessageBox(0, "Error Stopping Services", "Service Killed", MB_ICONERROR | MB_OK);
		WSACleanup();
		exit(-1);
	}

	WSACleanup();
	return res;
}