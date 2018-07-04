#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int strend(char *src, char *dst)
{
	int len_s;
	int len_d;
	int index;
	
	len_s = strlen(src) - 1;
	len_d = strlen(dst) - 1;

	for(index = 0; *(dst + index) != '\0'; index++)
	{
		if(*(src + len_s - index) != *(dst + len_d - index))
			return 0;
	}
	
	return 1;
}

int main(void)
{
    char *str = NULL;
    char *dst = NULL;
	int res;

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

	res = strend(str, dst);
	
	printf(" %d \n", res);
	
	return 0;
}
