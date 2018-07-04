#include "header.h"

void bubble_sort(int arr[], int size)
{
	int index1;
	int index2;

	for(index1 = 0; index1 < (size - 1); index1++){
		for(index2 = 0; index2 < (size - index1 - 1); index2++){
			if(arr[index2] > arr[index2 + 1]){
				swap(&arr[index2], &arr[index2 + 1]);
			}
		}
	}
}


