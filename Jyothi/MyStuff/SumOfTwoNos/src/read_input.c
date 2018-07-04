#include "header.h"

long long read_input(char *input)
{
	if(NULL == fgets(input, 32, stdin)){
		perror("fgets failed");

		exit(EXIT_FAILURE);
	}	

	int index = 0;

	while(input[index] != '\0')
		index++;

	input[index - 1] = '\0';

	return my_atoi(input);
}
