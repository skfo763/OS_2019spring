#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int *p = (int*)malloc(sizeof(int)*100);
	
	for(int i=0; i<100; i++) {
		p[i] = i;
	}
	
	return 0;
}

