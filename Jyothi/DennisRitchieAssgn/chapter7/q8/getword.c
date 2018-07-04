#include "header.h"

char buf[BUFSIZE];
int bufp = 0;

char getch( void )
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch( char c)
{
    if( bufp >= BUFSIZE)
        printf("ungetch : too many character");
    else
        buf[bufp++] = c;
}

/* getword: get next word or character from input */
int getword(char *word, int lim )
{
    char c, getch();
    void ungetch(char);
    char *w = word;
	c = getch();
    bzero(word,lim);
    if (c != EOF)
        *w++ = (char)c;
    if (!isalpha(c) ) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

