#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *data;
	data = (int *)malloc(sizeof(int) * 100);

	free(data);

	printf("data: %d\n", data[32]);
	// print one value of data;

	return 0;
}
