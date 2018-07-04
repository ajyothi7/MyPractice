#ifndef __HEADER__
#define __HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>
#define MAX 1000
#define BUFSIZE 100
#define FALSE 0
#define N_NOISE 13
#define MAXWORD 100

#define hndlr(msg) 	do{ \
			 perror(msg); exit(EXIT_FAILURE);}while(FALSE);

typedef struct node {
			char *word;
			int identical;
			struct node *left;
			struct node *right;
			} NODE;


NODE *addnode( NODE *, char *, int);

char *sstrdup( char *);

NODE *createnode( void );

int getword(char *, int, FILE *);

void ungetch( char , FILE *);

char getch( FILE *);

int strcmp_n( char *, NODE *, int );

void put_node( NODE *);

#endif



