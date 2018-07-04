#include "header.h"

void insertion_sort_rec(int arr[], int size)
{
	if(size <= 1)
		return;

	insertion_sort_rec(arr, size - 1);

	int key = arr[size - 1];
	int index = size - 2;

	while((index >= 0) && (arr[index] > key)){
		arr[index + 1] = arr[index];
		index--;
	}

	arr[index + 1] = key;
}
