// function to read input

#include "header.h"

char *read_input(char *input)
{
    if(NULL == fgets(input, MAX, stdin)){
        perror("fgets failed");
        exit(EXIT_FAILURE);
    }

	int index = 0;

	while(*(input + index) != '\0')
		index++;

	*(input + index - 1) = '\0';

	return input;
}
