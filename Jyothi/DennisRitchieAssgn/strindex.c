#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int strindex(const char *s, char t)
{
	int index;
	int count = -1;

	for (index = 0; *(s + index) != '\0'; index ++)
	{
		if (*(s + index) == t)
			count = index;
	}

	return count;
}

int main(void)
{
	char *ptr = NULL;
	char *ch = NULL;
	int ind = 0;

	if (NULL == (ptr = (char *)malloc(sizeof(char) * MAX))){
		printf ("malloc failed\n");
		return 1;
	}

	if (NULL == (ch = (char *)malloc(sizeof(char) * MAX))){
        printf ("malloc failed\n");
        return 1;
    }

	printf("Enter the string\n");

	if (NULL == fgets(ptr ,MAX, stdin)){
		printf("fgets failed\n");
		return 1;
	}

	printf("Enter the character\n");

	if (NULL == fgets(ch ,MAX, stdin)){
		printf("fgets failed\n");
		return 1;
	}

	if (*(ch + 2) != '\0'){
		printf("Enter only one character\n");
		return 0;
	}

	ind = strindex(ptr, *ch);

	if (ind == -1)
		printf("Character not found\n");

	else
		printf("Character is found at index %d\n", ind);

	free(ptr);
	free(ch);

	ptr = NULL;
	ch = NULL;

	return 0;
}
