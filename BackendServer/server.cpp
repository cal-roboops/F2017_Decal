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

struct pThread {
	int id;
	pthread_t* thread;
};

static int bufSize = 1024;
int rover;
list <pThread*> threads;

void terminateThread(int clientID) {
	for (list<pThread*> :: iterator it = threads.begin(); it != threads.end(); it++) {
		pThread* pt = *it;

		if (pt -> id == clientID) {
			pthread_cancel(*(pt -> thread));
			free(pt -> thread);
			free(pt);
			threads.erase(it);
			break;
		} 
	}
}

void *handleInput(void* client) {
	int clientID = *((int*) client);
	char buffer[bufSize];

	while (true) {
		if (recv(clientID, buffer, bufSize, 0) > 0) {
			if (buffer[0] == '#') {
				if (clientID == rover) {
					cout << "Rover disconnected." << endl;
				} else {
					cout << "Client (ID: " << clientID << ") disconnected." << endl;
				}
				terminateThread(clientID);
				return NULL;
			} else if ((int) buffer[0] == 0) {
				continue;
			} else if (clientID == rover) {
				cout << "ROVER: " << buffer << endl;
			} else {
				cout << "Client (ID: " << clientID << "): " << buffer << endl;
			}
			buffer[0] = 0;
		} else {
			cout << "Client (ID: " << clientID << "): " << buffer << endl;
			if (clientID == rover) {
				cout << "Lost connection with rover." << endl;
			} else {
				cout << "Lost connection with Client (ID: " << clientID << ")." << endl;
			}
			terminateThread(clientID);
			return NULL;
		}
	}
}

void createThread(int clientID) {
	int* clientIDPtr = &clientID;
	pthread_t* t = (pthread_t*) malloc(sizeof(pthread_t*));
	pThread* pt = (pThread*) malloc(sizeof(pThread*));

	pt -> id = clientID;
	pt -> thread = t;

	threads.push_back(pt);
	pthread_create(t, NULL, handleInput, (void*) clientIDPtr);
}

int main() {
	int MAX_SIZE_BACKLOG_QUEUE = 1;

	string str;

	int serverListener;
	int client;
	int portNum = 8088;

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

  	serverListener = socket(AF_INET, SOCK_STREAM, 0);

  	if (serverListener < 0) {
  		cout << "Error establishing connection." << endl;
  	} else {
  		cout << "Server socket connection established." << endl;
  	}

  	server_addr.sin_family = AF_INET;
  	server_addr.sin_port = htons(portNum);
  	server_addr.sin_addr.s_addr = INADDR_ANY;

  	if (bind(serverListener, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		cout << "Error binding socket." << endl;
		exit(1);
	}

	cout << "Ready to receive clients..." << endl;
	listen(serverListener, MAX_SIZE_BACKLOG_QUEUE);

	cout << "Waiting to connect to rover..." << endl;
	rover = accept(serverListener, (struct sockaddr*) &server_addr, &size);

	if (rover < 0) {
		cout << "Could not connect to rover." << endl;
		exit(1);
	} else {
		cout << "Connected to rover." << endl;
		createThread(rover);
	}

	while (true) {
		client = accept(serverListener, (struct sockaddr*) &server_addr, &size);

		if (client < 0) {
			cout << "Error on accepting client." << endl;
			exit(1);
		} else {
			cout << "Connected with new client. (ID: " << client << ")" << endl;
		}
		createThread(client);
	} 
}







