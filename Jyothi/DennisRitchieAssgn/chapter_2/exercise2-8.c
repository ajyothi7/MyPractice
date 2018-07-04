#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int invert(int,int,int);
char *readinput(char *);
int my_atoi(char *);

int main(void)
{
	char *input = NULL;
	int src;
	int no_of_bits;
	int res;

	if(NULL == (input = (malloc(sizeof(char)*MAX))))
	{
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	printf("enter the source\n");
	src = my_atoi(readinput(input));
	
	printf("enter the no_of_bits\n");
	no_of_bits = my_atoi(readinput(input));

	res = rightrot(src,no_of_bits);
	printf("%d",res);
	return 0;
}

/*Returns the value of the integer x rotated to the right by n bit positions */
int rightrot(int x,int n)
{
	return (x >> n ^ ((~(~(0) << n ) & x) << (32 -n)));
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

