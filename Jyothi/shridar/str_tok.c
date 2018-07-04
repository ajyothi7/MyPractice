#include "header.h"
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>

static char * str = NULL;
static int flag = 1;

char *str_tok(char *src,const char *delim)
{
		int i ;
		int j ;

		if( src == NULL)
				src = str;
		for (i = 0;*(src + i); i++) {
				for(j = 0;  delim[j]; j++) {
						if (*(delim + j) == *(src + i)) {
								str = src + i + 1;
								*(src + i) = '\0';

								if (*src != '\0')
										return src;
								else {
										src = str;
										i = -1;
										break;
								}
						}
				}
		}
		if (flag == 0)
				return NULL;
		if(src == str)
				flag = 0;
		return src;
}

void input_strtok(void)
{
		char *src =NULL;
		char *delim = NULL;
		char *tok = NULL;

		src = (char*)malloc(20 * sizeof(char));
		if (src == NULL) {
				printf("Memory is not available\n");
				exit(0);
		}
		printf("Enter source\n");
		if (NULL == fgets(src, 80,stdin)) {
				perror ("fgets");
				exit (EXIT_FAILURE);
		}
		src[strlen(src) - 1] = '\0';

		delim = (char*)malloc(20 * sizeof(char));
		if( delim == NULL) {
				printf("Memory is not available\n");
				exit(0);
		}
		printf("Enter delim string\n");
		if (NULL == fgets(delim,80,stdin)) {
				perror ("fgets");
				exit (EXIT_FAILURE);
		}
		delim[strlen(delim) - 1] = '\0';
		
		printf("source : %s\ndelim: %s\n",src,delim);
		
		tok = str_tok(src,delim);
		while( tok != NULL) {
				printf("%s\n",tok);
				tok = str_tok(NULL,delim);
		}
}
