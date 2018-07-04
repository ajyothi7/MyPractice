#include<stdio.h>
#include<stdlib.h>

#define MAX 256

char *expand(char s1[], char s2[]);

int main(void)
{
	char *src = NULL;
	char *dest = NULL;

	if(NULL == (src = malloc(sizeof(char) * MAX))){
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if(NULL == (dest = malloc(sizeof(char) * MAX))){
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	printf("enter the string\n");
	if(NULL == fgets(src,MAX,stdin)){
		printf("fgets failed\n");
		exit(EXIT_FAILURE);
	}

	dest = expand(src,dest);
	printf("result string:%s",dest);

	free(src);
	free(dest);

	return 0;
}


/*To expand shorthand notations like a-z in string s1 into string s2 */
char *expand(char s1[] , char s2[])
{
	char ch;
	int index1,index2;

	 index1 = 0;
	 index2 = 0;

	 while((ch = s1[index1++]) != '\0'){
	 	if((s1[index1] == '-') && (s1[index1 + 1] >= ch)){
			index1++;
			while(ch < s1[index1])
				s2[index2++] = ch++;
		}
		else
			s2[index2++] = ch;
	}
	s2[index2] = '\0';
	return s2;
}
