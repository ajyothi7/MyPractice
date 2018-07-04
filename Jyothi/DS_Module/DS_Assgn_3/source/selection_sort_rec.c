#include "header.h"

void selection_sort_rec(int arr[], int index1, int size)
{
	int index2;
	int min_index;
	int temp;

	if(index1 >= size)
		return;

	min_index = index1;

		for(index2 = index1 + 1; index2 < size; index2++){
			if(arr[index2] < arr[min_index])
				min_index = index2;
		}
	 	
		if(index1 != min_index){
				printf("%d %d\n", arr[min_index], arr[index1]);
			 // swap(&arr[min_index], &arr[index1]);
			 	temp = arr[min_index];
				arr[min_index] = arr[index1];
				arr[index1] = temp;
		}
		if(index1 + 1 < size)
			selection_sort_rec(arr, index1 + 1, size); 	
	

}
