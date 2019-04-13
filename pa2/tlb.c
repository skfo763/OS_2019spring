#define _GNU_SOURCE

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sched.h>
#include <stdint.h>

int main(int argc, char** argv) {
	struct timeval prev_time, curr_time;
	long long trial_time = 0;

	long number_of_page, number_of_trials;
	double result;	
	int pageSize, data, jump, i, j;
	int *arr, arr_size;

	pageSize = 4096;
	number_of_page = atoi(argv[1]);
	number_of_trials = atoi(argv[2]);

	data = (pageSize * number_of_page) / sizeof(int);
	arr = (int*)calloc(data, sizeof(int));

	jump = pageSize / sizeof(int);

	gettimeofday(&prev_time, NULL);
	
	for(i=0; i<number_of_trials; i++) {
		for(j=0; j<number_of_page*jump; j+=jump) {
			arr[j] += 1;
		}
	}

	gettimeofday(&curr_time, NULL);
	trial_time = (curr_time.tv_sec - prev_time.tv_sec) * 1000000 + (curr_time.tv_usec - prev_time.tv_usec);
	result = trial_time / (double) (number_of_page * number_of_trials);
	
	printf("%ld\t%ld\t%f\n", number_of_page, number_of_trials, result);

	return 0;
}

