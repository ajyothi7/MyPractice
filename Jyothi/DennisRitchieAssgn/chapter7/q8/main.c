#include "header.h"

#define isupper(c) c >= 'A' && c <= 'Z' ? 1 : 0

#define islower(c) c >= 'a' && c <= 'z' ? 1 : 0

int main(int argc, char *argv[] )
{
	char word[MAXWORD];
	char *ch[]={ "lower", "upper"};
	int i = 0;

	if(argc != 2)
		hndlr(" Provide choice : ./app upper/lower \n")
	
	if( strcmp(argv[1], ch[0]) == 0)
	
		while( getword( word, MAXWORD) != EOF) {
			i = 0;
			while( *(word+i) != '\0') {
				if( isupper(*(word+i)))
					*(word+i) += 32;
			i++;
			}		
			printf("%s",word);
		}				
	else if( strcmp(argv[1], ch[1]) == 0)
	
		while( getword( word, MAXWORD) != EOF) {
			i = 0;
			while( *(word+i) != '\0') {
				if( islower(*(word+i)))
					*(word+i) -= 32;
			i++;
			}		
			printf("%s",word);
		}	
	else 
		hndlr("Invalid choice!!!")

		
	return 0;
}

