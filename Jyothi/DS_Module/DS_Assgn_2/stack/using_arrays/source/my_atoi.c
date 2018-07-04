//function to convert ascii to integer

#include "header.h"

int my_atoi(char *str)
{
	int index;
	int num = 0;
	//int flag = 0;

	for(index = 0; (*(str + index) >= '0') && (*(str + index) <= '9');index++)
	{
		num = (10 * num) + (*(str + index) - '0');
	}

	if('-' == str [0]){
		num = 0 - num;
		//flag = 1;
	}

	if(((*(str + index) < '0') || (*(str + index) > '9')) && (str[index] != '\0'))
	{
		perror("invalid input");
		return -1;
	}
	
	printf("in my_atoi() -> %d\n",num);

	return num;
}
