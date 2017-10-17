#include <pthread.h>
#include <string.h>

#ifndef _functions_h
#define _functions_h

using namespace std;

struct Function {
	pthread_mutex_t lock;
	void (*func) (pthread_mutex_t*, string);
	void* data;
};

void test(pthread_mutex_t* lock, string key);

void initializeFunctions(struct Function**, int);

#endif