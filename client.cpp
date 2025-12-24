#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS


#include <winsock2.h>
#include <Windows.h>
#include <process.h>
#include <iostream>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <string>

#pragma comment(lib, "ws2_32")

using namespace std;

class Packet
{
public:
	string UserName;
	string Message;

	string ToJsonString()
	{
		string Temp = "";
		Temp = "{ \"UserName\" : ";
		Temp = Temp + " \"" + UserName + "\", ";
		Temp = Temp + " \"Message\" : ";
		Temp = Temp + " \"" + Message + "\" }";

		return Temp;
	}

	void Parse(string JsonString)
	{

	}
};


unsigned RecvThread(void* Arg)
{
	SOCKET ServerSocket = *(SOCKET*)Arg;

	char Buffer[1024] = { 0, };

	while (true)
	{
		int RecvBytes = recv(ServerSocket, Buffer, sizeof(Buffer), 0);

		cout << Buffer << endl;
	}
	return 0;
}

unsigned SendThread(void* Arg)
{
	SOCKET ServerSocket = *(SOCKET*)Arg;

	char Buffer[1024] = { 0, };

	while (true)
	{
		cout << "Chat : ";
		cin.getline(Buffer, sizeof(Buffer));
		int SendBytes = send(ServerSocket, Buffer, (int)strlen(Buffer) + 1, 0);
	}
	return 0;
}


int main()
{
	Packet D;
	cout << D.ToJsonString() << endl;

	return 0;

	WSAData wsaData;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET ServerSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN ServerSockAddr;
	memset(&ServerSockAddr, 0, sizeof(ServerSockAddr));
	ServerSockAddr.sin_family = AF_INET;
	ServerSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ServerSockAddr.sin_port = htons(33333);

	int Result = connect(ServerSocket, (SOCKADDR*)&ServerSockAddr, sizeof(ServerSockAddr));

	HANDLE SocketThread[2];
	SocketThread[0] = (HANDLE)_beginthreadex(0, 0, RecvThread, &ServerSocket, 0, 0);
	SocketThread[1] = (HANDLE)_beginthreadex(0, 0, SendThread, &ServerSocket, 0, 0);

	DWORD HResult = WaitForMultipleObjects(2, SocketThread, true, INFINITE);

	CloseHandle(SocketThread[0]);
	CloseHandle(SocketThread[1]);

	closesocket(ServerSocket);

	WSACleanup();

	return 0;
}
