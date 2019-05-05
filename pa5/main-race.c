#include <stdio.h>
#include <pthread.h>

int res = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_func(void* arg) {
	pthread_mutex_lock(&mutex);
	res++;
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main(void) {
	pthread_t t;
	
	if(pthread_create(&t, NULL, thread_func, NULL) != 0) {
		printf("thread create error\n");
		return -1;
	}
	pthread_mutex_lock(&mutex);
	res++;
	pthread_mutex_unlock(&mutex);
	pthread_join(t, NULL);
	return 0;
}


