#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int find_pattern( char *p_str, FILE *fp)
{
	char *line = NULL;
	size_t len;	
	char *res;
	while( getline( &line, &len, fp) != -1)
	{
		res = strstr(line, p_str);
		if(res == NULL)
			continue;
		else {
				free( line);
				return 1;
			}
	}
	
	return 0;
}


int main( int argc, char *argv[])
{
	FILE *fptr;
	char *pattrn = NULL;	
	char flag = 0;
	
	if( argc == 1) {
		printf("Provide atleast one file name\n");
		exit(EXIT_FAILURE);
	}
	else if( argc >= 2) {
		++argv;
		printf("Enter the pattern to be searched:\t");
		
		if( NULL == ( pattrn = (char *) malloc( sizeof( char) * MAX))) {
			printf("Malloc error\n");
			exit(EXIT_FAILURE);
		}
		
		if( NULL == fgets( pattrn, MAX, stdin)) {
			printf("Fgets error\n");
			exit(EXIT_FAILURE);
		}
		
		char *temp = pattrn;
		while(*temp++ != '\n');
		*(--temp) = '\0';
		
		while( --argc > 0) {
			
			if( (fptr = fopen( *argv, "r")) == NULL) {
				printf("error : can't open file %s\n", *argv);
				return 1;
			}
			else {
					if( find_pattern( pattrn, fptr) == 1) {
						printf("pattern is present in the file  %s\n",*argv);
						flag = 1;
					}
				}
			argv++;	
			}
		if(!flag)
			printf("Pattern %s not found\n", pattrn);
	}
	return 0;
}

