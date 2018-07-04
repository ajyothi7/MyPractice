#include "header.h"

typedef void (*fun) (char *);

void upper(char *src)
{
	while( *src != '\0') {
		if( *src >= 'a' && *src <= 'z')
		{
			*src = *src - 32;
		}
		src++;
	}
	
}

void lower(char *src)
{
	while( *src != '\0') {
		if( *src >= 'A' && *src <= 'Z')
		{
			*src = *src + 32;
		}
		src++;
	}
	
}

int main(int argc, char *argv[] )
{
	char word[MAXWORD];
	fun fun_ptr;
	char *ch[]={ "lower", "upper"};

	if(argc != 2)
		hndlr(" Provide choice : ./app upper/lower \n")
	
	if( strcmp(argv[1], ch[0]) == 0)
		fun_ptr = lower;
	else if( strcmp(argv[1], ch[1]) == 0)
		fun_ptr = upper;
	else 
		hndlr("Invalid choice!!!")

	while( getword( word, MAXWORD) != EOF) {
			fun_ptr(word);
		printf("%s",word);}
		
	return 0;
}

