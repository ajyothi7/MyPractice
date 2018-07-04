#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int invert(int,int,int);
int my_atoi(char *);
char *readinput(char *);

int main(void)
{
	char *input = NULL;
	int src;
	int pos;
	int no_of_bits;
	int res;

	if(NULL == (input = (malloc(sizeof(char)*MAX))))
	{
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	printf("enter the source\n");
	src = my_atoi(readinput(input));
	
	printf("enter the position\n");
	pos = my_atoi(readinput(input));
	
	printf("enter the no_of_bits\n");
	no_of_bits = my_atoi(readinput(input));

	res = invert(src,pos,no_of_bits);
	printf("%d",res);
	return 0;
}

/* Returns x with the n bits that begin at position p inverted*/
int invert(int x,int p,int n)
{
	return x ^ ((~(~(0) << n)) << (p-n+1));
}

/*to convert ascii to integer */
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

/*to read input */
char* readinput(char *input)
{
    if(NULL == (fgets(input,MAX,stdin))){
		perror("fgets failed");
		exit(EXIT_FAILURE);
	}

	return input;
}
