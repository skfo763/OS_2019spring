#include <stdio.h>
#include <pthread.h>

pthread_mutex_t glob = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

void* thread_func(void* arg) {
	pthread_mutex_lock(&glob);
	if((long long) arg == 0) {
		pthread_mutex_lock(&m1);
		pthread_mutex_lock(&m2);
	} else {
		pthread_mutex_lock(&m2);
		pthread_mutex_lock(&m1);
	}
	pthread_mutex_unlock(&m1);
	pthread_mutex_unlock(&m2);
	pthread_mutex_unlock(&glob);
	return NULL;
}

int main(void) {
	pthread_t p1, p2;
	pthread_create(&p1, NULL, thread_func, (long long) 0);
	pthread_create(&p2, NULL, thread_func, (long long) 1);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	return 0;
}
