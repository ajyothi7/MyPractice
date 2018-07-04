#include "header.h"

int main(void)
{
	char *input = NULL;
	int num1;
	int num22;

	if(NULL == (input = (char *) malloc(sizeof(int) * MAX))){
		printf("malloc failed");
		return EXIT_FAILURE;
	}

	printf("enter an num1:");
	input = read_input(input);
	if((num = my_atoi(input)) > INT_MAX){
		printf("invalid input");
		return EXIT_FAILURE;
	}

	printf("enter an num2:");
	input = read_input(input);
	if((num = my_atoi(input)) > INT_MAX){
		printf("invalid input");
		return EXIT_FAILURE;
	}

	printf("given number: %d\n", (int)num);

	return 0;
}
