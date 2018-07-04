#include "header.h"

void bubble_sort_rec(int arr[], int size)
{

	if(size == 1)
		return;

	int index1;

	for(index1 = 0; index1 < (size - 1); index1++){
		if(arr[index1] > arr[index1 + 1]){
			swap(&arr[index1], &arr[index1 + 1]);
		}
	}

	bubble_sort(arr, size - 1);
}


