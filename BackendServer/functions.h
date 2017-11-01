#include <iostream>
#include <string.h>
#include <pthread.h>
#include <string.h>
#include <sys/socket.h>
#include <list>

#ifndef _functions_h
#define _functions_h

using namespace std;

struct Thread {
	int socket_desc;
	pthread_t* pthread;
	long ip;
	int port;
};

struct Function {
	pthread_mutex_t lock;
	void (*func) (struct Function*, list<struct Thread*>, string, int, int);
	void* data;
};

void test(struct Function*, list<struct Thread*>, int, int);

void initializeFunctions(struct Function**, int);

#endif