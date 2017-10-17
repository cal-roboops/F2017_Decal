#include <iostream>
#include <string.h>
#include <pthread.h>
#include <string.h>
#include <sys/socket.h>

#ifndef _functions_h
#define _functions_h

using namespace std;

struct Function {
	pthread_mutex_t lock;
	void (*func) (pthread_mutex_t*, string, void*, int, int);
	void* data;
};

void test(pthread_mutex_t*, string, void*, int, int);

void initializeFunctions(struct Function**, int);

#endif