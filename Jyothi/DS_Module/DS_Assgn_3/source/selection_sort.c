#include "header.h"

void selection_sort(int arr[], int size)
{
	int index1;
	int index2;
	int min_index;

	for(index1 = 0; index1 < (size - 1); index1++){

		min_index = index1;

		for(index2 = index1 + 1; index2 < size; index2++){
			if(arr[index2] < arr[min_index]){
				min_index = index2;
				//swap(&arr[min_index], &arr[index1]);
			}
		}
		
		if(index1 != min_index)
			swap(&arr[min_index], &arr[index1]);
	}
}


