#include <stdio.h>
#include <stdlib.h>

void print_data(int *vector, int size) {
	for(int i=0; i<size; i++) {
		printf("%d ", vector[i]);
	}
	printf("\nsize of vector is %d\n", size);
}

int main(void) {
	int *vector;
	int size = 0;

	vector = (int*)malloc(sizeof(int));

	
	while(size < 8) {
		if(size != 0) {
			vector = (int *)realloc(vector, sizeof(int)*(size+1));
		}
		printf("input : ");
		scanf("%d", &vector[size]);
		size++;

		print_data(vector, size);
	}

	free(vector);
	return 0;
}

