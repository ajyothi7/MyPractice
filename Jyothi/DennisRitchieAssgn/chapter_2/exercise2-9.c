#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int bitcount(unsigned int);
char *readinput(char *);
int my_atoi(char *);

int main(void)
{
	char *input = NULL;
	unsigned int src;
	int res;

	if(NULL == (input = (malloc(sizeof(char)*MAX))))
	{
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	printf("enter the source\n");
	src = my_atoi(readinput(input));
	

	res = bitcount(src);
	printf("Number of set bit :%d\n",res);
	
	return 0;
}

/*Returns the value of the integer x rotated to the right by n bit positions */
int bitcount(unsigned int x)
{
	int count = 0;
	while(x != 0)
	{
		x = x & (x - 1);
		count++;
	}
	return count;
}

/* To read input */
char* readinput(char *input)
{
	if(NULL == (fgets(input,MAX,stdin))){
		perror("fgets failed");
		exit(EXIT_FAILURE);
	}
	return input;
}

/* To convert ascii to integer */
int my_atoi(char *str)
{
	int index;
	int num;

	num = 0;

	for(index = 0 ; *(str + index) >= '0' && *(str+index) <= '9' ; index++){
		num = 10 * num + (*(str+index) - '0');
	}

	return num;
}

