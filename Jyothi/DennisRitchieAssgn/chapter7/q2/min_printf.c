#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

#define MAX 100

void minprintf( char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;
	int i;
	char frmt[MAX];	
	unsigned uval;
	va_start(ap,fmt);
	for(p = fmt; *p ; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		
	i = 0;
	frmt[i++] = '%';
	while( *(p+1) && !isalpha(*(p+1)))
		frmt[i++] = *++p;
	frmt[i++] = *(p+1);
	frmt[i] = '\0';
		switch( *++p) {
		case 'd' :
		case 'i' :
					ival = va_arg( ap, int);
					printf(frmt, ival);
					break;
		case 'x' :
		case 'X' :
		case 'u' :
		case 'o' :
					uval = va_arg( ap, unsigned);
					printf(frmt, uval);
					break;
		case 'f' :
					dval = va_arg( ap, double);
					printf(frmt, dval);
					break;
		case 's' :
					for(  sval = va_arg(ap, char *) ; *sval; sval++)
						putchar(*sval);
					break;
		default:
					printf(frmt,0);
					break;
		}
	}
	
	va_end(ap);
	
}
