#include "header.h"

int main(int argc, char *argv[] )
{
	FILE *fptr;
	NODE *root = NULL;
	char word[MAXWORD];
	int linenum = 1;

	if(argc != 2)
		hndlr(" Provide file name: ./app file_name \n")
	if( NULL == ( fptr = fopen( argv[1],"r")))
		hndlr("Can't open file ")	

	while( getword( word, MAXWORD, fptr) != EOF) {
		if( isalpha( word[0]))
			{
			if(-1 == noiseword(word))
			root = addnode( root, word, linenum);
			}
	else if( word[0] == '\n' )
			{linenum++;
			}
		}

	print_node( root );
	return 0;
}

