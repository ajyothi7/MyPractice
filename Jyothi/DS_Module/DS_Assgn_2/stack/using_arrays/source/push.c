#include "header.h"

int push(int data, int top)
{
	if(top > MAX){
		perror("stack full\n");
		return 0;
	}

	arr[++top] = data;

	return top;
}
