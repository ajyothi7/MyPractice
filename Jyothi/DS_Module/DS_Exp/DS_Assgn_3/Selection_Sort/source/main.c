#include "header.h"

int main(void)
{
	char *input = NULL;
	int size;

	if(NULL == (input = (char *)malloc(sizeof(char *)))){
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	printf("enter the array size\n");
	size = my_atoi(read_input(input));

	int arr[size];
	int index = 0;

	printf("enter the array elements\n");
	for(index = 0; index < size; index++){
		arr[index] = my_atoi(read_input(input));
	}

	printf("before sorting\n");
	print_array(arr, size);

	//selection_sort(arr, size);
	selection_sort_rec(arr, 0, size);

	printf("sorting successful\n");
	printf("after sorting\n");
	print_array(arr, size);
	return 0;
}
