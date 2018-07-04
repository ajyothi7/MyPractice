#include <stdio.h>
#define MAX 256

int lower (char );

int main(void)
{
	char input ;
	int res;

	printf("enter the character\n");
	input = getchar();
	
	res = lower(input);
	printf("%c\n",res);

	return 0;
}

int lower(char c)
{
	return ( c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c ; 
}
