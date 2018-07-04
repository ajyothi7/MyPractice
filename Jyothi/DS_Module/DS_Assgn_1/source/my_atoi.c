//function to convert ascii to integer

#include "header.h"

int my_atoi(char *str)
{
	int index;
	int num = 0;
	
	if(*(str + 0) == '\n'){
		perror("invalid input");
//		exit(EXIT_FAILURE);
		return -1;
	}

	for(index = 0; (*(str + index) >= '0') && (*(str + index) <= '9');index++)
	{
		num = (10 * num) + (*(str + index) - '0');
	}

	if(((*(str + index) < '0') || (*(str + index) > '9')) && (str[index] != '\n'))
	{
		perror("invalid input");
		exit(EXIT_FAILURE);
	}
	
	return num;
}
