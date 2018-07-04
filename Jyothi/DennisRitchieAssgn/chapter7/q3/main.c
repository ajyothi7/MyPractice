#include <stdio.h>
#include <stdlib.h>

void minscanf( char *, ...);

int main( void )
{
	int num = 10;
	float flt = 10.10;
	char *str = "C PROGRAMMING ";	

	minscanf( "%d",&num);
	minscanf( "%f", &flt);
	minscanf( "%s", str);
	
	printf(" %d, %f , %s", num, flt,str );
 
	return 0;
}

