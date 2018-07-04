#include "header.h"

char buf[BUFSIZE];
int bufp = 0;

char getch(FILE *fptr)
{
    return (bufp > 0) ? buf[--bufp] : fgetc( fptr);
}

void ungetch( char c, FILE * fptr)
{
    if( bufp >= BUFSIZE)
        printf("ungetch : too many character");
    else
        buf[bufp++] = c;
}

char single_line( FILE *fptr)
{
	char ch;
	while( (ch = getch( fptr ) ) != EOF)
	{
		if(ch == '\n')
			break;
	}
	return ch;
}

char multi_line(FILE *fptr )
{
	char ch;
	while( (ch = getch( fptr) )!= EOF ) {
		if( ch == '*') {
			if( (ch = getch( fptr))	== '/')
				break;
			else
				ungetch( ch , fptr);		
		}
	}
	return ch;
}

/* getword: get next word or character from input */
int getword(char *word, int lim, FILE *fptr)
{
    char c, temp, getch(FILE *);
    void ungetch(char, FILE *);
    char *w = word;

   // bzero(word,lim);
    while (isblank(c = getch( fptr )));
	
	if( c != EOF  )
	*(w++) = c;
	if( (isalpha(c) ) || (c == '_') || (c == '#')) {
		    	for ( ; --lim > 0; w++){
        			if (!isalnum(*w = getch( fptr )) && (*w != '_')) {
            			ungetch(*w,fptr);
          	  		break;
        			}	
			}
	}
	else if( c == '\'' || c == '"') {
			
			for( ; --lim > 0; w++)
				if( (*w = getch( fptr )) == '\\')
						*(++w) = getch( fptr);
				else if( *w == c) {
						w++;
						break; 
					}
				else if( *w == EOF)
					break;
			}
			else if( c == '/') {
						
					if( ( temp = getch(fptr) ) == '/')
						c = single_line(fptr);
					else if(temp == '*')
						c = multi_line(fptr);
					else 
						ungetch(temp , fptr);
				}
		*w = '\0';
		return c;
}

