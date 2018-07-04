#include "header.h"

int display(int top)
{
	if(top == -1){
		printf("stack empty\n");
		return 0;
	}

	int index;
	
	printf("stack elements are \n");
	for(index = top; index > -1; index--)
		printf("%d\n", arr[index]);

	return 1;
}
