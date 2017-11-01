#include "functions.h"

using namespace std;
const int messageSize = 1024;

void test(struct Function* function, list<struct Thread*> clientThreads, string key, int clientSocket, int roverSocket) {
	pthread_mutex_lock(&(function -> lock));

	list<struct Thread*>::const_iterator iterator;
	string roverMessage = "Command: " + key;
	string clientResponse = "Command received.";
	string updateMessage = "Update: " + key;

	send(clientSocket, "Command received.", messageSize, 0);
	//send(roverSocket, roverMessage.c_str(), messageSize, 0);

	for (iterator = clientThreads.begin(); iterator != clientThreads.end(); iterator++) {
		struct Thread* t = *iterator;

		if (t -> socket_desc != clientSocket) {
			send(t -> socket_desc, updateMessage.c_str(), messageSize, 0);
		}
	}

	cout << "Test complete.\n" << endl;

	pthread_mutex_unlock(&(function -> lock));
}

void initializeFunctions(struct Function** functions, int len) {
	struct Function* f;

	for (int i = 0; i < len; i++) {
		f = (struct Function*) malloc(sizeof(struct Function));

		if (f == NULL) {
			cout << "Failed to allocate memory for function." << endl;
			exit(1);
		} else if (pthread_mutex_init(&(f -> lock), NULL) < 0) {
			cout << "Failed to initialize mutex." << endl;
			exit(1);
		}
		f -> func = &test; //remove when done testing
		functions[i] = f;
	}
	
	//functions[0] -> func = &test;
}
