#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 256

char *strncpy_(char *s, char *t, int n)
{
	int index = 0;
//	int len;
	
//	len = strlen(s) - 1;
	while(n != 0)
	{
		*(s + index) = *(t + index);
		index++;
		n--;
	}
	
	return s;
}

char *strncat_(char *s, char *t, int n)
{
	int index = 0;
	int len_s;
	int len_t;
	
	len_s = strlen(s) - 1;
	len_t = strlen(t) - 1;
	
	for (index = 0; index < n; index++)
	{
		*(s + len_s + index) = *(t + index);
	}
	*(t + index) = '\0';
	
	return s;
}
	
int strncmp_(char *s, char *t, int n)
{
	int index;
	int len_s;
	
	len_s = strlen(s);
	for(index = 0; index < n; index++)
	{
		if(*(s + index) != *(t + index))
			if(*(s + index) > *(t + index))
				return 1;
			else
				return -1;
	}
	
	return 0;
}
	
int main(void)
{
	char *str = NULL;
	char *dest = NULL;
	int n;
	int ch;
	
	printf("Press: \n"
		"1. strnpy(src, dst, n) \n" 
		"2. strncat(src, dst, n) \n"
		"3. strncmp(src, dst, n)\n");
	
	printf("\n\n");
	printf("Enter your choice = ");
	if(NULL == (str = (char *) malloc(sizeof(char) * MAX)))
	{
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if(NULL == (fgets(str, MAX, stdin)))
	{
		perror("fgets failed\n");
		exit(EXIT_FAILURE);
	}
	ch = atoi(str);

	printf("Enter a string: \t");
	if(NULL == (str = (char *) malloc(sizeof(char) * MAX)))
	{
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if(NULL == (fgets(str, MAX, stdin)))
	{
		perror("fgets failed\n");
		exit(EXIT_FAILURE);
	}
		
	printf("\n");
	printf("Enter another string: \t");
	if(NULL ==(dest = (char *) malloc(sizeof(char) * MAX)))
	{
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if(NULL == (fgets(dest, MAX, stdin)))
	{
		perror("fgets failed\n");
		exit(EXIT_FAILURE);
	}
	printf("\n");
	printf("Enter number of characters to be replaced / placed: ");
	scanf("%d", &n);
	
	switch(ch)
	{
		case 1:
			str = strncpy_(str, dest, n);
			printf("str = %s\n", str);
			break;
		case 2:
			str = strncat_(str, dest, n);
			printf("str = %s\n", str);
			break;
		case 3:
			n = strncmp_(str, dest, n);
			printf("%d\n", n);
			break;
		default:
			printf("Invalid input\n");
	}	
	
	return 0;
}
