#include <stdio.h>
#include <string.h>

#define BUFSIZE 10
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("Stack full\n");

	else
		buf[bufp++] = c;
}

void ungets(char *s)
{
	int i, len;
	len = strlen(s);
	if(BUFSIZE - bufp >= len)
	{
		for(i = strlen(s) - 1; i >=0; i--)
			ungetch(s[i]);
	}
	else
		printf("insufficient space in buffer\n");
}

int main(void)
{
	char s[] = "welcome\n";
	int c;
	ungets(s);
	while((c = getch()) != EOF)
		putchar(c);

	return 0;
}

