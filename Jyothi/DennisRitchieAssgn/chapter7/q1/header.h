#ifndef __HEADER__
#define __HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>

#define BUFSIZE 100
#define FALSE 0
#define N_NOISE 13
#define MAXWORD 100

#define hndlr(msg) 	do{ \
			 perror(msg); exit(EXIT_FAILURE);}while(FALSE);


int getword(char *, int);

void ungetch( char );

char getch( );


#endif



