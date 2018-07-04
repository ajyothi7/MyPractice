#include <stdio.h>
#include <stdlib.h>

void minprintf( char *, ...);

int main( void )
{
	int num = 10;
	float flt = 10.10;
	char *str = "C PROGRAMMING ";	

	minprintf( "Integer = %d\n", num);
	minprintf( "float = %f\n", flt);
	minprintf( "string = %s\n", str);
	 
	return 0;
}

