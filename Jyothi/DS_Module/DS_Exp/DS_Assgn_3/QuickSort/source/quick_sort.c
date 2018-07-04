#include "header.h"

void quick_sort_rec(int arr[], int low, int high)
{

    int part;

    if (low < high)
    {
		part = partition(arr, low, high);

		//recursively performing quicksort

		quick_sort(arr, low, part - 1);

		quick_sort(arr, part + 1, high);

    }

}
