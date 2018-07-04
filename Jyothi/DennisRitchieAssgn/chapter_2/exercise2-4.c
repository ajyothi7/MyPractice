#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

char *squeeze(char *,const char *);

int main(void)
{
	char *res = NULL;
	char *str = NULL;
	char *sstr = NULL;

	if(NULL == (str = malloc(sizeof(char)*MAX))){
		printf("malloc failed");
		exit(EXIT_FAILURE);
	}
	if(NULL == (sstr = malloc(sizeof(char)*MAX))){
		printf("malloc failed");
		exit(EXIT_FAILURE);
	}
	
	printf("Enter the string\n");
	if(NULL == (fgets(str, MAX, stdin))){
		printf("fgets failed\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Enter the substring\n");
	if(NULL == (fgets(sstr,MAX,stdin))){
		printf("fgets failed\n");
		exit(EXIT_FAILURE);
	}

	str = squeeze(str, sstr);
	printf("%s\n",str);

	free(sstr);
	free(str);

	
	return 0;

}

/*Deletes each character in s1 that matches any character in string s2*/
char *squeeze(char *str, const char *sstr)
{
	int index1 = 0;
	int index2 = 0;
	int index3 = 0;
	char *buf = NULL;
	int flag = 0;

	if(NULL == (buf = (malloc(sizeof(char)*MAX)))){
		printf("malloc failed");
		exit(EXIT_FAILURE);
	}
	strcpy(buf,str);
	while(*(buf + index1) != '\0'){
		flag = 0;
		for(index2 = 0; *(sstr + index2) != '\0' ; index2++){
			if(*(sstr + index2) == *(buf + index1)){
				flag = 1;
			}
		}
		if(flag != 1){
			*(str + index3) = *(buf + index1);
			index3++;
		}
	
		index1++;
	}
	*(str + index3) = '\0';
	
	free(buf);
	return str;
}
