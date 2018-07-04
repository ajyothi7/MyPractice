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

/* getword: get next word or character from input */
int getword(char *word, int lim, FILE *fptr)
{
    char c, getch(FILE *);
    void ungetch(char, FILE *);
    char *w = word;

    bzero(word,lim);
    while (isblank(c = getch( fptr )));
    if (c != EOF)
        *w++ = (char)c;
    if (!isalpha(c) ) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch( fptr ))) {
            ungetch(*w,fptr);
            break;
        }
    *w = '\0';
 // printf("in getch %s\n",word);
    return word[0];
}

