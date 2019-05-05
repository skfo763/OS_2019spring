#include <stdio.h>
#include <pthread.h>

int done = 0;

void* thread_func(void* arg) {
	printf("this should print first\n");
	done = 1;
	return NULL;
}

int main(void) {
	pthread_t p1;
	pthread_create(&p1, NULL, thread_func, NULL);
	while(done == 0) ;
	
	printf("this should print last\n");
	return 0;
}
