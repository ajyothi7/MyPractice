#include <stdio.h>
#include <stdlib.h>

#define MAX 255

int binary_search(int, int *, int);
char *readinput(char *);
int my_atoi(char *);

int main()
{
	char *ptr;
	int key;
	int flag;
	int i;
	int size;

	if (NULL == (ptr = ((char *) malloc(sizeof(char) * MAX)))) {
		perror("malloc failure");
		exit(EXIT_FAILURE);
	}

	printf("size of the array\n");
	size = my_atoi(readinput(ptr));
	int arr[size];
	printf("enter the array of elements\n");
	for (i = 0; i < size; i++) {
		arr[i] = my_atoi(readinput(ptr));
	}

	printf("enter the key element\n");
	key = my_atoi(readinput(ptr));

	flag = binsearch(key, arr, size);

	if (flag != -1)
		printf("element found \n");
	else
		printf("element not found \n");

	return 0;

}

/* To search an element using binary search algorithm */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && (x != v[mid])) {
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}
	if (x == v[mid])
		return mid;
	else
		return -1;
}

/* To read input */
char *readinput(char *input)
{
	if (NULL == (fgets(input, MAX, stdin))) {
		perror("fgets failed");
		exit(EXIT_FAILURE);
	}
	return input;
}

/* To convert ascii to integer */
int my_atoi(char *str)
{
	int index;
	int num;

	num = 0;

	for (index = 0; *(str + index) >= '0' && *(str + index) <= '9'; index++) {
		num = 10 * num + (*(str + index) - '0');
	}

	return num;
}
