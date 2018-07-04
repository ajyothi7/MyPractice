#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hndlr(msg) do{ \
				perror(msg); exit(0);} while( 0);

int main(int argc, char *argv[])
{
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	
	size_t len1 = 0;
	size_t len2 = 0;		
	
	ssize_t r1, r2;
	
	char *line1 = NULL;
	char *line2 = NULL;

	if( argc != 3 )
	{	
		hndlr("Provide file name: ./app file1 file2 \n")
	}
	
	fp1 = fopen( argv[1], "r");
	fp2 = fopen( argv[2], "r");
	
	if( fp1 == NULL || fp2 == NULL )
		hndlr("error: Cant open file")
	else
		while( ((r1 = getline( &line1, &len1,fp1)) != -1) && 
				((r2 = getline( &line2, &len2, fp2)) != -1)) {
		if( (len1 == len2) && (strcmp(line1,line2) == 0))
				continue;
		else
			{	
				printf("files are not same \n");
				printf("%s", line1);
				printf("%s", line2);
				break;
			}
		}
		
		free(line1);
		free(line2);

		fclose(fp1);
		fclose(fp2);

		return 0;
}
			
