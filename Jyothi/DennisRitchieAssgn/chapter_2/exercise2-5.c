#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int any(char *,const char*);
int main(void)
{
	char *str = NULL;
	char *sstr = NULL;
	int res;

	if(NULL == (str = malloc(sizeof(char)*MAX))){
		printf("malloc failed");
		exit(EXIT_FAILURE);
	}
	if(NULL == (sstr = malloc(sizeof(char)*MAX))){
		printf("malloc failed");
		exit(EXIT_FAILURE);
	}

	printf("enter the string:\n");
	if(NULL == (fgets(str, MAX, stdin))){
		printf("fgets failed");
		exit(EXIT_FAILURE);
	}

	printf("enter the substring:");
	if(NULL == (fgets(sstr, MAX, stdin))){
		printf("fgets failed");
		exit(EXIT_FAILURE);
	}
	res = any(str, sstr);

	if(res != -1)
		printf(" first location that matches substring character:%d\n",res);
	else
		printf("location not found\n");

	return 0;

}

/*Returns first location int the string str,where any character from the string sstr occurs*/
int any(char *str, const char *sstr)
{
	int index1 = 0;
	int index2 = 0;

	while(*(str + index1) != '\0'){
		for(index2 = 0; *(sstr + index2) != '\0' ;index2++){
			if( *(sstr + index2) == *(str + index1))
				return index1+1;
		}
		index1++;
	}
	return -1;
}
