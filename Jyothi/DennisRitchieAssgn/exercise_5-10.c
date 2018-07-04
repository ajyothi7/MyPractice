#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50

int a[MAX];
int pos = 0;
int top = -1;

void push(int data)
{
	top++;
	if(top == MAX)
		perror("stack full: ");
	a[top] = data;
}	

int pop()
{
	int data;
	
	if(top == -1)
		perror("stack empty: ");
	data = a[top];
	top--;
	return data;
}

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

int mul(int num1, int num2)
{
	return num1 * num2;
}

int div_(int num1, int num2)
{
	return num1 / num2;
}

int mod(int num1, int num2)
{
	return num1 % num2;
}

int pow_(int num1, int num2)
{
/*	int val;
	val =  pow(num1, num2);
	return val;
*/

	int index;
	int res = 1;
	for(index = 0; index < num1; index++)
	{
		res = res * num2;
	}
	return res;
}

int main(int argc, char *argv[])
{
	int index;
	int val1;
	int val2;
	int res;
	
	for(index = 1; index < argc; index++)
	{
		printf("%s\n", argv[index]);
		if(*argv[index] >= '0' && *argv[index] <= '9')
		{
			val1 = atoi(argv[index]);
			push(val1);			
		}
		else
		{
			val1 = pop();
			val2 = pop();
			
			if(*argv[index] == '+')
				res = add(val1, val2);
			else if(*argv[index] == '-')
				res = sub(val1, val2);
			else if(*argv[index] == '*')
				res = mul(val1, val2);
			else if(*argv[index] == '/')
				res = div_(val1, val2);
			else if(*argv[index] == '%')
				res = mod(val1, val2);
			else if(*argv[index] == '^')
				res = pow_(val1, val2);
			else
			{
				perror("Invalid operator input: ");
				exit(EXIT_FAILURE);
			}
			push(res);	
		}
	}
//	printf("\n");	
	printf("Result = %d\n", res);
	
	return 0;
}
