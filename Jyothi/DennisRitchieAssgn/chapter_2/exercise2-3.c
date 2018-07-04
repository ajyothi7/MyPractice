#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define BUF 256

int htoi(char *);
char *remsstr(char *, const char *);

int main(void)
{
	char *input;				/*to get hexadecimal value */
	int res;
	if (NULL == (input = (malloc(sizeof(char) * BUF)))) {
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (NULL == (fgets(input, BUF, stdin))) {
		printf("fgets failed\n");
		exit(EXIT_FAILURE);
	}

	input = (char *) remsstr(input, "0x");
	input = (char *) remsstr(input, "0X");

	res = htoi(input);
	if (res != -1)
		printf("%d", res);
	else
		printf("invalid input\n");

	free(input);
	return 0;
}

/* to convert hexadecimal to integer */
int htoi(char *str)
{
	int len = strlen(str) - 1;
	int count = 1;
	int sum = 0;
	int i = 0;
	int index = len - 1;

	while ((len != 0)) {
		count = pow(16, i);
		i++;
		if ((*(str + index) == 'a') || (*(str + index) == 'A'))
			sum = sum + count * 10;
		else if ((*(str + index) == 'b') || (*(str + index) == 'B'))
			sum = sum + count * 11;
		else if ((*(str + index) == 'c') || (*(str + index) == 'C'))
			sum = sum + count * 12;
		else if ((*(str + index) == 'd') || (*(str + index) == 'D'))
			sum = sum + count * 13;
		else if ((*(str + index) == 'e') || (*(str + index) == 'E'))
			sum = sum + count * 14;
		else if ((*(str + index) == 'f') || (*(str + index) == 'F'))
			sum = sum + count * 15;
		else if ((*(str + index) >= '0') && (*(str + index) <= '9'))
			sum = sum + count * (*(str + index) - '0');
		else {
			sum = -1;
			break;
		}
		index--;
		len--;
	}
	return sum;
}

/* To remove substring  from string */
char *remsstr(char *str, const char *rstr)
{
	int flag = 0;
	int index1;
	int index2;
	int len;
	int slen;

	len = strlen(str);
	slen = strlen(rstr);
	for (index1 = 0; index1 <= (len - slen); index1++) {
		flag = 1;
		for (index2 = 0; index2 < slen; index2++) {
			if (*(str + (index2 + index1)) != *(rstr + index2)) {
				flag = 0;
				break;
			}
		}

		if (flag == 1) {
			for (index2 = index1; index2 <= (len); index2++) {
				*(str + index2) = *(str + (index2 + slen));
			}
			len = len - slen;
		}
	}

	return str;
}
