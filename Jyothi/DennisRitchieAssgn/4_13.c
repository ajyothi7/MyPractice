#include <stdio.h>
#include <string.h>

int reverse(char v[], int i, int j)
{
	int temp;
	if(j <= i)
	    return 1;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	reverse(v, ++i, --j);
}

int main(void)
{
	char test[] = "Chirag";
	reverse(test, 0, strlen(test)-1);
	printf("%s\n", test);

	return 0;
}

