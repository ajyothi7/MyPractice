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

typedef struct list{
			int line;
			struct list *n_list;
			} LIST;

typedef struct node {
			char *word;
			int count;
			struct node *left;
			struct node *right;
			LIST *list;
			} NODE;


typedef struct noise_w {
			char *word;
			} NOISE_W;

//NOISE_W noise_word[] = { "a", "an", "and", "but", "if", "is", "of", "the", "there"};
//char buf[BUFSIZE];
//int bufp = 0;						

NODE *addnode( NODE *, char *, int);

char *sstrdup( char *);

NODE *createnode( void );

void print_node( NODE *);

int getword(char *, int, FILE *);

void ungetch( char , FILE *);

char getch( FILE *);

int binsearch( char*, NOISE_W *, int );

int noiseword( char *);
#endif



