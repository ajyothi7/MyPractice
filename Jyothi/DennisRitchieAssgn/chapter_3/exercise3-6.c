#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int, char *,int);
char *reverse (char *);

int main(void)
{
	char *input = NULL;
	char *str = NULL;
	int num;
	int width;

	if (NULL == (input = malloc(sizeof(char) * MAX))) {
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (NULL == (str = malloc(sizeof(char) * MAX))) {
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter a number\n");
	if (NULL == fgets(input, MAX, stdin)) {
		printf("fgets failed\n");
		exit(EXIT_FAILURE);
	}

	num = atoi(input);
	
	printf("Enter the width\n");
	if (NULL == fgets(input, MAX, stdin)) {
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	width = atoi(input);

	itoa(num, str, width);

	free(str);
	free(input);
	return 0;
}

/* itoa : convert n to characters in s */
void itoa(int n, char s[],int w)
{
	int i, sign;

	sign = n;
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	
	s = reverse(s);
	
	while(i < w)
		s[i++] = ' ';
	
	s[i] = '\0';
	printf("%s\n", s);
}

/*To reverse a string */
char *reverse(char *str1)
{
	int index;
	int len = 0;
	char *buf = NULL;
	if (NULL == (buf = (char *) malloc(sizeof(char) * MAX))) {
		perror("malloc failure");
		exit(EXIT_FAILURE);
	}

	len = strlen(str1);

	for (index = 0; len != 0; index++) {
		*(buf + index) = *(str1 + (len - 1));
		len--;
	}

	return buf;
	free(buf);
}
