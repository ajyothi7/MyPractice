#include "header.h"

NODE arry[MAX];
int num = 0;

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
			root = addnode( root, word, linenum);
			}
	put_node(root, &num, arry);
	sort_arry(num, arry);	
	print_arry(num, arry);
	return 0;
}

