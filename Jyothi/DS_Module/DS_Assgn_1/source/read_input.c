// function to read input

#include "header.h"

char * read_input(char *input)
{
    if(NULL == (fgets(input, MAX, stdin))){
		perror("fgets failed");
		exit(EXIT_FAILURE);
	}

	return input;
}

