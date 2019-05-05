#include <stdio.h>
#include <pthread.h>
typedef struct syncronizer_t {
	pthread_mutex_t lock;
	pthread_cond_t cond;
	int done;
} sc_t; 
sc_t s;

void signal_init(sc_t *s){
	pthread_mutex_init(&s->lock, NULL);
	pthread_cond_init(&s->cond, NULL);
	s->done = 0;
}

void signal_done(sc_t *s) {
	pthread_mutex_lock(&s->lock);
	s->done = 1;
	pthread_cond_signal(&s->cond);
	pthread_mutex_unlock(&s->lock);
}

void signal_wait(sc_t *s) {
	pthread_mutex_lock(&s->lock);
	while(s->done == 0)  pthread_cond_wait(&s->cond, &s->lock);
	pthread_mutex_unlock(&s->lock);
}

void* thread_func(void* arg) {
	printf("this should print first\n");
	signal_done(&s);
	return NULL;
}

int main(void) {
	pthread_t p;
	signal_init(&s);
	pthread_create(&p, NULL, thread_func, NULL);
	signal_wait(&s);
	printf("this should print last\n");
	return 0;
}


