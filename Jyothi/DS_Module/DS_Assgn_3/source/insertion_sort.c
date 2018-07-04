#include "header.h"

void insertion_sort(int arr[], int size)
{
	int index1;
	int index2;
	int key;

	for(index1 = 1; index1 < size; index1++){
		
		key = arr[index1];
		index2 = index1 - 1;

		while((index2 >= 0) && (arr[index2] > key)){
			arr[index2 + 1] = arr[index2];
			index2 = index2 - 1;
		}

		arr[index2 + 1] = key;
	}
}
