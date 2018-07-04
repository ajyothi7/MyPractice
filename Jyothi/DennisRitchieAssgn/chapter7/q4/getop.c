#include "header.h"

char arry[ ]= " ";

int getop( char s[])
{
	int i;
	char c;
	int temp ;	
	sscanf(arry, "%c", &c);
	*(arry + 0) = ' ';
	
	while( (s[0] = c ) == ' ' || c == '\t')
		if( scanf("%c", &c) == EOF)
			c = EOF;
	s[1] = '\0';
	
	if( !isdigit( c) &&  c != '.')
		return c;
	i = 0;
	if( isdigit(c) )
		do{
			temp = scanf( "%c", &c);
			if( !isdigit(s[++i] = c ))
				break;
			}while( temp != EOF);

	if( c == '.' )
		do{
			temp = scanf("%c", &c);
			if(!isdigit(s[++i] = c))
				break;
			} while( temp != EOF);
	s[i] = '\0';
	if( temp != EOF)
		arry[0] = c;
	return NUM;
	
}
