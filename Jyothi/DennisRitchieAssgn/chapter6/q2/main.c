#include "header.h"


int main(int argc, char *argv[] )
{
	FILE *fptr;
	char word[MAXWORD];
	int n_char = 6;
	NODE *root = NULL;

	if(argc < 2)
		hndlr(" Provide file name: ./app file_name \n")
	if(argc == 3)
	n_char = atoi(argv[2]);	

	if( NULL == ( fptr = fopen( argv[1],"r")))
		hndlr("Can't open file ")	

	while( getword( word, MAXWORD, fptr) != EOF) {
			//printf("%s",word);
			if( isalpha( word[0]) || word[0] == '_' ) {
				if( strlen(word) >= n_char)
				{
					//printf("%s\n", word);
					root = addnode( root, word, n_char);
				}
			}
	}

	printf(" variable group having %d starting characters identical are:\n",n_char);	
	put_node( root );
	return 0;
}

