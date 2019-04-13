#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

int main(int argc, char** argv) {
	
	struct timeval tv;
	int page_count = atoi(argv[1]);
	int trial_count = atoi(argv[2]);
	int *arr, count = 0;
	long sum = 0;
	long prev_mic, curr_mic;
	long prev_time, curr_time;
	uint64_t trialtime = 0;

	arr = (int*)malloc(sizeof(int)*page_count);
	memset(arr, 0, sizeof(int)*page_count);

	while(count <=  trial_count) {
		gettimeofday(&tv, NULL);
		prev_time = tv.tv_sec;
		prev_mic = tv.tv_usec;

		for(int i=0; i<page_count; i++) {
			arr[i]++;
		}
		
		gettimeofday(&tv, NULL);
		curr_time = tv.tv_sec;
		curr_mic = tv.tv_usec;

		count++;

		trialtime = (curr_time - prev_time)*1000000 + (curr_mic - prev-mic); 
		



	}

	return 0;
}
