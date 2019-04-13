#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* data;
	data = (int*)malloc(sizeof(int) * 100);

	free(data);

	printf("middle data: %d\n", data[50]);

	free(data);
	return 0;
}
