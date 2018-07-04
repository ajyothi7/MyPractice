#include "header.h"

int pop(int top)
{
	if(top == -1){
		printf("stack empty\n");
		return 0;
	}

	//--top;

	return --top;
}
