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

#include <json/value.cpp>
#include <json/writer.cpp>

using namespace std;

int main() {
	int client;
	int iResult;
	int value;
	int portNum = 8088;
	int bufSize = 1024;
	char buffer[bufSize];
	string serialized;
	Json::Value jobj;
	Json::StreamWriterBuilder writer;
	writer.settings_["indentation"] = "";
	const char *ip = "127.0.0.1";

	struct sockaddr_in server_addr;

	// Setup Windows sockets if on windows
	#ifdef WIN32
	WSADATA wsaData;
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

	if (iResult != 0)
	{
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
	} else
	{
		cout << "Client socket created." << endl;
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(portNum);

	#ifdef WIN32
	InetPton(AF_INET, ip, &(server_addr.sin_addr));
	#else
	inet_pton(AF_INET, ip, &(server_addr.sin_addr));
	#endif

	// Connecting to socket server.
	if (connect(client, (struct sockaddr*) &server_addr, sizeof(server_addr)) == 0)
	{
		cout << "Connecting to server..." << endl;
	}

	cout << "Connection confirmed." << endl;
	cout << "Use ctrl + c to end the connection.\n" << endl;

	while (true) {
		cout << "Key: ";
		cin.getline(buffer, sizeof(buffer));

		jobj[0] = Json::Value(buffer);

		cout << "Value: ";
		cin.getline(buffer, sizeof(buffer));

		value = buffer[0] - '0';
		jobj[1] = Json::Value(value);

		serialized = Json::writeString(writer, jobj);

		send(client, serialized.c_str(), bufSize, 0);
		cout << "\n";
	}
	
	close(client);
	return 0;
}