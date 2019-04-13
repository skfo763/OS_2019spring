#include <stdio.h>
#include <math.h>
#include <sched.h>

double waste_time(long n) {
	double res = 0;
	long i = 1;

	while(i < n*500000) {
		i++;
		res += sqrt(i);
	}

	return res;
}

int main(int argc, char** argv) {
	unsigned long mask = 1;

	if(sched_setaffinity(0, sizeof(mask), &mask) < 0) {
		perror("sched_setaffinity error\n");	
	}

	printf("result : %lf\n", waste_time(2000));

	
	return 0;
}
