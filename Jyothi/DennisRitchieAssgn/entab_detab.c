#include <stdio.h>
#include <stdlib.h>
#define MAX 256

char *entab(char *str, int count)
{
	int index1 = 0;
	char *sstr = NULL;
	int index3 = 0, index2 = 0;

	if(NULL == (sstr = (char *) malloc(sizeof(char) * MAX)))
	{
		perror("malloc failed: ");
		exit(EXIT_FAILURE);
	}
	
	for(index1 = 0; *(str + index1) != '\n'; index1++)
	{
		if((*(str + index1) == ' ') && count != 0)
		{
			for(index3 = 0; index3 < 4; index3++)
			{
//				*(sstr + j + k)	= ' ';
				*(sstr + index2) = ' ';
				index2++;
			}
			count--;
		}
		else
		{
//			*(sstr + j + k) = *(str + i);
			*(sstr + index2) = *(str + index1);
			index2++;
		}
	}
	
//	printf("sstr = %s\n", sstr);

	return sstr;
}

char *detab(char *str, int count)
{
	int index1 = 0, index2 = 0;
	char *sstr = NULL;
	int cnt = 0;
		
	if(NULL == (sstr = (char *) malloc(sizeof(char) * MAX)))
	{
		perror("malloc failed: ");
		exit(EXIT_FAILURE);
	}
	
	for(index1 = 0; *(str + index1) != '\n'; index1++)
	{
		if((*(str + index1) == ' ') && count != 0)
		{
			cnt++;
			if(cnt == 4 )	
			{
				*(sstr + index2) = ' ';
				index2++;
				cnt = 0;
				count--;
			}
		}
		else
		{
			*(sstr + index2) = *(str + index1);
			index2++;
		}
	}
	
	return sstr;
}

int main(int argc, char *argv[])
{
	char *str = NULL;
	char *ch = NULL;
	int choice;
	int count;
	
	if(argc == 2)
		count = atoi(argv[1]);

	printf("Enter a string including spaces and tab =  ");
	if(NULL == ( str = (char *) malloc(sizeof(char) * MAX)))
	{
		perror("malloc failed: ");
		exit(EXIT_FAILURE);
	}
	if(NULL == (fgets(str, MAX, stdin)))
	{
		perror("fgets failed: ");
		exit(EXIT_FAILURE);
	}

	printf("Press:\n"
		"1. Entab operation\n"
		"2. Detab operation\n");

	if(NULL == (ch = (char *) malloc(sizeof(char))))
	{
		perror("malloc failed: ");
		exit(EXIT_FAILURE);
	}
	if(NULL == (fgets(ch, MAX, stdin)))
	{
		perror("fgets failed: ");
		exit(EXIT_FAILURE);
	}
	
	choice = atoi(ch);
	free(ch);

	switch(choice)
	{
		case 1:
			str = entab(str, count);
			printf("entabbed string = %s\n", str);
			break;
		case 2:
			str = detab(str, count);
			printf("detabbed string = %s\n", str);
			break;
		default:
			perror("Invalid input: ");
	}

	return 0;
}
