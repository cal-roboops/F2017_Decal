#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>

#include <json/value.cpp>
#include <json/reader.cpp>
#include <json/writer.cpp>

#include "functions.h"

using namespace std;

struct Thread {
	int socket_desc;
	pthread_t* pthread;
	long ip;
	int port;
};

const long roverIP = 0;
const int bufSize = 1024;
const int numFuncs = 5;
struct Thread* roverThread;
struct Function* functions[numFuncs];

void terminateThread(struct Thread*);

void *handleInput(void*);

void createThread(int, long, int);

int main() {
	const int MAX_SIZE_BACKLOG_QUEUE = 5;
	int serverListener;
	int client;
	int portNum = 8088;
	int size = sizeof(struct sockaddr_in);
	struct sockaddr_in server_addr, client_addr;

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
	initializeFunctions(functions, numFuncs);

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

	pthread_create(pt, NULL, handleInput, (void*) t);

	if (ipAddr == roverIP) {
		roverThread = t;
	}
}

void *handleInput(void* threadStruct) {
	struct Thread* t = (struct Thread*) threadStruct;
	struct Function* f;
	int socketID = t -> socket_desc;
	char buffer[bufSize];
	bool parsingSuccessful;
	int val;
	string jsonString;
	Json::Value jobj;
	Json::CharReaderBuilder reader;
	reader["collectComments"] = false;
	JSONCPP_STRING errs;

	while (true) {
		if (recv(socketID, buffer, bufSize, 0) > 0) {
			if (buffer[0] == 0) {
				continue;
			} else if (t -> ip == roverIP) {
				cout << "ROVER: " << buffer << endl;
			} else {
				istringstream istr(buffer);
				parsingSuccessful = Json::parseFromStream(reader, istr, &jobj, &errs);

				if (!parsingSuccessful) {
					cout << "Test Failed: could not deserialize command\n" << endl;
					send(t -> socket_desc, "Failed to deserialize command.", bufSize, 0);
				} else {
					cout << "Client (IP: " << t -> ip << ", Port: " << t -> port << "): Key: " << jobj[0] << ", Value: " << jobj[1] << endl;
					val = jobj[1].asInt();

					if (val < numFuncs && val >= 0) {
						// check to make sure roverThread != NULL
						f = functions[jobj[1].asInt()];
						f -> func(&(f -> lock), jobj[0].asString(), f -> data, t -> socket_desc, -1); // -1 will be replaced with roverThread -> socket_desc
					} else {
						cout << "Test Failed: value out of range\n" << endl;
						send(t -> socket_desc, "Value out of range.", bufSize, 0);
					}
				}
			}
		} else {
			if (t -> ip == roverIP) {
				cout << "\nDisconnected with ROVER.\n" << endl;
				roverThread = NULL;
			} else {
				cout << "\nDisconnected with Client (IP: " << t -> ip << ", Port: " << t -> port << ").\n" << endl;
			}

			terminateThread(t);
			close(socketID);
			return NULL;
		}
	}
}

void terminateThread(struct Thread* t) {
	pthread_cancel(*(t -> pthread));
	free(t -> pthread);
	free(t);
}
