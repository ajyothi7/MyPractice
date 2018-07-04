#include "header.h"

void print_array(int arr[], int size)
{
	int index;

	for(index = 0; index < size; index++)
		printf("%d\t", arr[index]);

	printf("\n");
}
