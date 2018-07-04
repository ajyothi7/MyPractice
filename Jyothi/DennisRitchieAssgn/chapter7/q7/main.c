#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CHAR 80
#define MAX_LINE 42
#define HEADER 3


void display_file( FILE *fp, char *filename)
{
	int line_n;
	int page_n = 1;
	char *ptr = NULL;
	int maxword;
	
	printf("\n");
	printf("filename = %s\t\tpage %d\n", filename, page_n++);
	printf("\n");
	line_n = 3;
	
	while( getline(&ptr, &maxword, fp) != -1) {
		if( line_n == 1) {
			printf("\n");
			printf("filename = %s\t\tpage %d\n", filename, page_n++);
			printf("\n");
			line_n = 3;
			}
	printf("%s",ptr);
	if( ++line_n > MAX_LINE )
		line_n = 1;
	}

	while(line_n++ < MAX_LINE)
		printf("\n");
}
int main( int argc, char *argv[])
{
	FILE *fp = NULL;

	if( argc == 1)
		{
			printf("Provide atleast one filename as arguement\n");
			return 1;
		}
	else
		{	
			while( --argc > 0 ) {

				if( (fp = fopen( *++argv, "r")) == NULL) {
					printf("error : can't open %s\n", *argv);
					}
				else {
						display_file( fp, *argv);
						fclose(fp);
					}
		}
		}
	return 0;
}
