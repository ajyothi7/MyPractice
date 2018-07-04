#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int setbits(int,int,int,int);
char *readinput(char *);
int my_atoi(char *);

int main(void)
{
	char *input = NULL;
	char *dest1 = NULL;
	char *pos1 = NULL;
	char *no_of_bits1 = NULL;
	int src;
	int dest;
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
	
	printf("enter the destination\n");
	dest = my_atoi(readinput(input));

	printf("enter the position\n");
	pos = my_atoi(readinput(input));
	
	printf("enter the no_of_bits\n");
	no_of_bits = my_atoi(readinput(input));

	res = setbits(src,pos,no_of_bits,dest);
	printf("%d",res);
	return 0;
}

/* Returns x with the n bits that begin at position p set to the rightmost n bits of y */
int setbits(int x,int p,int n, int y)
{
	return ((~(((1 << n) - 1) << (p-n+1)) & x) | ((y & ((1<<n)-1)) << (p-n+1)));
}

/*To read input */
char* readinput(char *input)
{
    if(NULL == (fgets(input,MAX,stdin))){
		perror("fgets failed");
		exit(EXIT_FAILURE);
	}

	return input;
}

/*To convert ascii to integer */
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

