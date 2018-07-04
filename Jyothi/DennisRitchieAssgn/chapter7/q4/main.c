#include "header.h"

#define MAX 100
#define NUM '0'

int main( void )
{
	int type;
	double op2;
	char str[MAX];
	
	while(( type = getop (str )) != EOF ) {
		switch( type ) {
		case NUM :
					push(atof(str));
					break;
		case '+' :
					push( pop() + pop() );
					break;
		case '-' :
					op2 = pop();
					push ( pop() - op2 );
					break;
		case '*' :
					push( pop() * pop());
					break;
		case '/' :
					op2 = pop();
					if( op2 != 0.0 )
						push( pop() - op2);
					else 
						printf( "error: zero divisor \n");
					break;
		case '\n' :
				 	printf("\t%.8g\n", pop());
					break;
		default :
					printf("error : unknown command %s\n", str);
					break;
		}

	}
	
	return 0;
}
