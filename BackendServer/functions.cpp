#include "functions.h"

using namespace std;
const int messageSize = 1024;

void test(pthread_mutex_t* lock, string key, void* data, int clientSocket, int roverSocket) {
	pthread_mutex_lock(lock);

	send(roverSocket, "Message received.", messageSize, 0);
	send(clientSocket, "Message received.", messageSize, 0);
	cout << "Test complete.\n" << endl;

	pthread_mutex_unlock(lock);
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
