#include <stdio.h>
#include <stdlib.h>

#define MAX 256

char *escape(char *, char *);
char *unescape(char *, char *);
char *readinput(char *);

int main(void)
{
	char *src = NULL;
	char *dest = NULL;

	if (NULL == (src = malloc(sizeof(char) * MAX))) {
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (NULL == (dest = malloc(sizeof(char) * MAX))) {
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	printf("enter the string to print escape sequence \\t \\n:\n");
	src = readinput(src);

	dest = escape(dest, src);

	printf("string: %s\n", dest);

	free(src);
	free(dest);

	if (NULL == (src = malloc(sizeof(char) * MAX))) {
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (NULL == (dest = malloc(sizeof(char) * MAX))) {
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	printf("enter the string to remove escape sequence \\n \\t:\n");
	src = readinput(src);

	dest = unescape(dest, src);

	printf("string: %s\n", dest);

	free(src);
	free(dest);
	return 0;
}

/* To print escape sequences '\n' and '\t' */
char *escape(char *s, char *t)
{
	int index1 = 0;
	int index2 = 0;

	for (index1 = 0; *(t + index1) != '\0'; index1++) {
		switch (*(t + index1)) {
		case '\n':
			*(s + index2) = '\\';
			index2++;
			*(s + index2) = 'n';
			index2++;
			break;
		case '\t':
			*(s + index2) = '\\';
			index2++;
			*(s + index2) = 't';
			index2++;
			break;
		default:
			*(s + index2) = *(t + index1);
			index2++;
		}
	}
	*(s + index2) = '\0';

	return s;
}

/* To print escape sequences into real character */
char *unescape(char *s, char *t)
{
	int index1 = 0;
	int index2 = 0;

	for (index1 = 0; *(t + index1) != '\0'; index1++) {
		if( *(t + index1) != '\\'){
			*(s + index2) = *(t + index1);
			index2++;
		}
		else{

			switch (*(t + index1+1)) {
				case 'n':
					*(s + index2) = '\n';
					index2++;
					index1++;
				break;
				case 't':
					*(s + index2) = '\t';
					index2++;
					index1++;
				break;
				default:
					*(s + index2) = '\\';
					index2++;
					*(s + index2) = *(t + index1);
					index2++;
			}	
		}
	}
	*(s + index2) = '\0';

	return s;
}

/* To read input */
char *readinput(char *input)
{
	if (NULL == (fgets(input, MAX, stdin))) {
		perror("fgets failed");
		exit(EXIT_FAILURE);
	}
	return input;
}
