#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256


void itob(int, char *,int);
char *reverse (char *);

int main(void)
{
	char *input = NULL;
	char *str = NULL;
	int num;
	int base;

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

	printf("Enter a base\n");
	if (NULL == fgets(input, MAX, stdin)) {
		printf("fgets failed\n");
		exit(EXIT_FAILURE);
	}
	base = atoi(input);

	itob(num, str, base);

	free(str);
	free(input);
	return 0;
}

/* itob : convert n to base b  characters representation in s */
void itob(int n, char s[], int b)
{
	int i,j, sign;
	
	if((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		j = n % b;
		s[i++] = ((j <= 9) ? (j + '0'): (j + 'a' - 10));
	} while ((n /=b) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	s = reverse(s);
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
