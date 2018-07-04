//function to allocate space 

#include "header.h"

char * allocate_space(char *data)
{
	if(NULL == (data = (char *)malloc(sizeof(char *) * MAX))){
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	return data;
}
