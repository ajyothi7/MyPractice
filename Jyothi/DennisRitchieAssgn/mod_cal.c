#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 256

int main(void)
{
	printf("Enter two numbers\n");

	char *ptr = NULL;
	double num1 = 0;
	double num2 = 0;
	double result = 0;
	
	if (NULL == (ptr = (char *)malloc(sizeof(char) * MAX))){
        printf ("malloc failed\n");
        return 1;
    }

	if (NULL == fgets(ptr ,MAX, stdin)){
        printf("fgets failed\n");
        return 1;
    }

	num1 = atoi(ptr);

	if (NULL == fgets(ptr ,MAX, stdin)){
        printf("fgets failed\n");
        return 1;
    }

    num2 = atoi(ptr);
	result = fmod(num1, num2);

	printf("The result is %d\n", (int)result);

	free(ptr);
	ptr = NULL;

	return 0;
}
