// function to validate integer

#include "header.h"

void validate_int(int num)
{
	if(num > INT_MAX){
		perror("invalid range");
		exit(EXIT_FAILURE);
	}
}
