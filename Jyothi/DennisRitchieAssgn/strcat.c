#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

char *strcat_(char *src, char *dst)
{
	int index;
	int len_s;
	
	len_s = strlen(src) - 1;
	for(index = 0; *(dst + index) != '\n'; index++)
	{
		*(src + len_s + index) = *(dst + index);
	}
	*(dst + index) = '\0';
	
	return src;
}

int main(void)
{
	char *str = NULL;
	char *dst = NULL;	

	printf("Enter a source string = ");
	if(NULL ==( str = (char *) malloc(sizeof(char) * MAX)))
	{
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if(NULL ==(fgets(str, MAX, stdin)))
	{
		perror("fgets failed\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Enter the destination string = ");
	if(NULL == (dst = (char *) malloc(sizeof(char) * MAX)))
	{
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if(NULL == (fgets(dst, MAX, stdin)))
	{
		perror("fgets failed\n");
		exit(EXIT_FAILURE);
	}
	
	strcat_(str, dst);
	
	printf("Modifies source string  = %s\n", str);
		
	return 0;
}
