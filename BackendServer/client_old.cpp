#ifdef WIN32
#define WINVER 0x0A00
#define _WIN32_WINNT 0x0A00
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#endif

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


using namespace std;

int main()
{

	string str;

	int client;
	int portNum = 8088;
	int bufSize = 1024;
	char buffer[bufSize];
	const char *ip = "127.0.0.1";

	struct sockaddr_in server_addr;

	// Setup Windows sockets if on windows
	#ifdef WIN32
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
  if (iResult != 0) {
      cout << "WSAStartup failed with error: " << iResult << endl;
      return -1;
  }
	#endif

	// Initializing socket.
	client = socket(AF_INET, SOCK_STREAM, 0);

	if (client < 0) 
	{
		cout << "Error creating socket." << endl;
		exit(1);
	}
	cout << "Client socket created." << endl;

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(portNum);
	#ifdef WIN32
	InetPton(AF_INET, ip, &(server_addr.sin_addr));
	#else
	inet_pton(AF_INET, ip, &(server_addr.sin_addr));
	#endif

	// Connecting to socket server.
	if (connect(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0)
	{
		cout << "Connecting to server..." << endl;
	}

	recv(client, buffer, bufSize, 0);
	cout << "Connection confirmed" << endl;
	cout << "Enter # to end the connection." << endl;

	while (true) {
		cout << "Client: ";
		cin.getline(buffer, sizeof(buffer));
		send(client, buffer, bufSize, 0);
	};

	close(client);
	return 0;
}