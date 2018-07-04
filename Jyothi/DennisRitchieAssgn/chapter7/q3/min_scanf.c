#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

#define MAX 100

void minscanf( char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int *ival;
	double *dval;
	int i;
	char frmt[MAX];	
	unsigned *uval;
	
	i = 0;
	va_start(ap,fmt);
	for(p = fmt; *p ; p++) {
		if (*p != '%') {
			frmt[i++] = *p;
			continue;
		}
		
	frmt[i++] = '%';
	while( *(p+1) && !isalpha(*(p+1)))
		frmt[i++] = *++p;
	frmt[i++] = *(p+1);
	frmt[i] = '\0';
		switch( *++p) {
		case 'd' :
		case 'i' :
					ival = va_arg( ap, int *);
					scanf(frmt, ival);
					break;
		case 'x' :
		case 'X' :
		case 'u' :
		case 'o' :
					uval = va_arg( ap, unsigned *);
					scanf(frmt, uval);
					break;
		case 'f' :
					dval = va_arg( ap, double *);
					scanf(frmt, dval);
					break;
		case 's' :
					sval = va_arg(ap, char *);
					scanf(frmt, sval);
					break;
		default:
					scanf(frmt);
					break;
		}
		
		i = 0;
	}
	
	va_end(ap);
	
}
