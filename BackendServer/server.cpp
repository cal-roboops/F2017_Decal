#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <list>

#ifdef WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <pthread.h>
#endif

using namespace std;

struct Thread {
	int socket_desc;
	pthread_t* pthread;
	long ip;
	int port;
};

const long roverIP = 0;
const int bufSize = 1024;
list <struct Thread*> threads;

void terminateThread(long, int);

void *handleInput(void*);

void createThread(int, long, int);

int main() {
	const int MAX_SIZE_BACKLOG_QUEUE = 5;
	int serverListener;
	int client;
	int portNum = 8088;
	int size = sizeof(struct sockaddr_in);

	struct sockaddr_in server_addr, client_addr;

	// Setup Windows sockets if on windows
	#ifdef WIN32
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

  	if (iResult != 0) { 
  		cout << "WSAStartup failed with error: " << iResult << endl;
      	return 1;
  	}
	#endif

  	serverListener = socket(AF_INET, SOCK_STREAM, 0);

  	if (serverListener < 0) {
  		cout << "Error establishing connection." << endl;
  	} else {
  		cout << "Server socket connection established." << endl;
  	}

  	server_addr.sin_family = AF_INET;
  	server_addr.sin_port = htons(portNum);
  	server_addr.sin_addr.s_addr = INADDR_ANY; // will be replaced by IP of communication receiver on rover

  	if (bind(serverListener, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
		cout << "Error binding socket." << endl;
		exit(1);
	} else {
		cout << "Ready to receive clients..." << endl;
	}

	listen(serverListener, MAX_SIZE_BACKLOG_QUEUE);

	while (true) {
		client = accept(serverListener, (struct sockaddr*) &client_addr, (socklen_t*) &size);

		if (client < 0) {
			cout << "Error on accepting client." << endl;
		} else {
			if (client_addr.sin_addr.s_addr == roverIP) {
				cout << "\nSuccessfully connected to ROVER.\n" << endl;
			} else {
				cout << "\nSuccessfully connected to new client." << endl;
				cout << "Client IP: " << client_addr.sin_addr.s_addr << endl;
				cout << "Client port: " << ntohs(client_addr.sin_port) << "\n" << endl;
			}
			createThread(client, client_addr.sin_addr.s_addr, ntohs(client_addr.sin_port));
		}
	} 
}

void createThread(int socketID, long ipAddr, int p) {
	pthread_t* pt = (pthread_t*) malloc(sizeof(pthread_t));
	struct Thread* t = (struct Thread*) malloc(sizeof(struct Thread));

	t -> socket_desc = socketID;
	t -> pthread = pt;
	t -> ip = ipAddr;
	t -> port = p;

	threads.push_back(t);
	pthread_create(pt, NULL, handleInput, (void*) t);
}

void *handleInput(void* threadStruct) {
	struct Thread* t = (struct Thread*) threadStruct;
	int socketID = t -> socket_desc;
	char buffer[bufSize];

	while (true) {
		if (recv(socketID, buffer, bufSize, 0) > 0) {
			if (buffer[0] == 0) {
				continue;
			} else if (t -> ip == roverIP) {
				cout << "ROVER: " << buffer << endl;
			} else {
				cout << "Client (IP: " << t -> ip << ", Port: " << t -> port << "): " << buffer << endl;
			}
		} else {
			if (t -> ip == roverIP) {
				cout << "\nDisconnected with ROVER.\n" << endl;
			} else {
				cout << "\nDisconnected with Client (IP: " << t -> ip << ", Port: " << t -> port << ").\n" << endl;
			}
			terminateThread(t -> ip, t -> port);
			close(socketID);
			return NULL;
		}
	}
}

void terminateThread(long ipAddr, int p) {
	for (list<struct Thread*> :: iterator it = threads.begin(); it != threads.end(); it++) {
		struct Thread* t = *it;

		if ((t -> ip == ipAddr) && (t -> port == p)) {
			pthread_cancel(*(t -> pthread));
			free(t -> pthread);
			free(t);
			threads.erase(it);
			break;
		} 
	}
}







