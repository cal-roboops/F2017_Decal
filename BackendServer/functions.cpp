#include <iostream>
#include <string.h>
#include "functions.h"

using namespace std;

void test(pthread_mutex_t* lock, string key) {
	pthread_mutex_lock(lock);
	cout << "Test Output: " << key << "\n" << endl;
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
