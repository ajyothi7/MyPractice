#include "header.h"

int main(int argc, char *argv[] )
{
	FILE *fptr;
	char word[MAXWORD];

	if(argc != 2)
		hndlr(" Provide file name: ./app file_name \n")
	if( NULL == ( fptr = fopen( argv[1],"r")))
		hndlr("Can't open file ")	

	while( getword( word, MAXWORD, fptr) != EOF) {
			//printf("%s",word);
			if( isalpha( word[0]) || word[0] == '_' || word[0] == '#' || word[0] == '\'' || word[0] == '"')
			printf("%s\n", word);
			if( word[0] == EOF)
			break;
	}
	return 0;
}

