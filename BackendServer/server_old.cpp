#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#endif

using namespace std;

int main() 
{
	int MAX_SIZE_BACKLOG_QUEUE = 1;

	string str;

	int client, server;
	int portNum = 8088;
	int bufSize = 1024;
	char buffer[bufSize];

	struct sockaddr_in server_addr;
	socklen_t size;

	// Setup Windows sockets if on windows
	#ifdef WIN32
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
  if (iResult != 0) {
      cout << "WSAStartup failed with error: " << iResult << endl;
      return 1;
  }
	#endif
	
	// Initializing socket conenction.
	client = socket(AF_INET, SOCK_STREAM, 0);

	if (client < 0) 
	{
		cout << "Error establishing connection." << endl;
		exit(1);
	}
	cout << "Server socket connection established." << endl;

	// server byte order/
	server_addr.sin_family = AF_INET;
	// convert short integer value for port must 
	// be converted into network byte order.
	server_addr.sin_port = htons(portNum);
	// automatically be filled with current host's IP address.
	server_addr.sin_addr.s_addr = INADDR_ANY;

	// Binding socket.
	if (bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		cout << "Error binding socket." << endl;
		exit(1);
	}

	connect:
	size = sizeof(server_addr);
	cout << "Looking for clients..." << endl;

	// Listening socket.
	listen(client, MAX_SIZE_BACKLOG_QUEUE);

	// Accepting client.
	server = accept(client, (struct sockaddr*)&server_addr, &size);

	if (server < 0)
	{
		cout << "Error on accepting a client." << endl;
		exit(1);
	} else {
		strcpy(buffer, "Server connected...");
		send(server, buffer, bufSize, 0);

		cout << "Connected with client." << endl;
		cout << "Enter # to end the connection." << endl;
	}

	while (server > 0) {
		#ifdef WIN32
		ZeroMemory(buffer, sizeof(buffer));
		#endif
		cout << "Client: ";
		if (recv(server, buffer, bufSize, 0) <= 0)
		{
			cout << "Client disconnected!" << endl;
			goto connect;
		}
		cout << buffer << endl;
		send(server, buffer, bufSize, 0);
	}

	close(client);
	return 0;
}