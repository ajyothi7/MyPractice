#include"header.h"

char * str_str(const char *src,const char *substr)
{
	char *s1  =(char *)src;

	char *s2 = NULL;
	
	char *s3 = NULL;
	
	while(*s1) {
	
			s2 = (char*)s1;
		
			s3 = (char*)substr;
			
			while(*s1 && *s3 && (*s1 == *s3)) {
			
					s1++;
				
					s3++;
			
			}
			
			if(!*s3)
			
					return s2;
			
			s1 = s2+1;
			
	}
	
	return NULL;

}

void input_strstr(void)
{
	char *str1 = NULL;
	
	char *str2 = NULL;
	
	str1 = (char*)malloc(20 *sizeof(char));
	
	if(str1 == NULL) {
	
			printf("Memory is not available\n");
		
			exit(0);
	
	}
	
	printf("Enter string1:\n");
	
	if (NULL== fgets(str1,80,stdin)) {
			perror("fgets");
			exit (EXIT_FAILURE);
	}
	
	str1 = string_validation(str1);
	
	str2 = (char*)malloc(20 * sizeof(char));
	
	if(str2 == NULL) {
	
			printf("Memory is not available\n");
		
			exit(0);
	
	}
	
	printf("Enter string2:\n");
	
	if (NULL == fgets(str2,80,stdin)) {
			perror ("fgets");
			exit (EXIT_FAILURE);
	}
	str2 = string_validation(str2);

	printf("str1:%s\n",str1);
	
	printf("str2:%s\n",str2);

	str1= str_str(str1,str2);
	
	if(str1 != NULL) {
	
			printf("the string is:%s\n",str1);
		
			printf("the string found in :%p\n",str1);
	
	}
		
	else {

		printf("string is not found\n");
	}
}
