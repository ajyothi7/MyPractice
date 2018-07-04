#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int count = 10;	
	int c;
	int cnt_nw_line = 0;

	if(argc < 2)
	{
		perror("no input file: ");
		exit(EXIT_FAILURE);
	}

	fp = fopen(*(argv + 1), "r");
	
	if(NULL == fp)
	{
		perror("file opening failed: ");
		exit(EXIT_FAILURE);
	}
	
	if(argc == 3)
		count = atoi(*(argv + 2));	
	
	printf("count = %d\n", count);
	
	while((c = getc(fp)) != EOF)
	{
		if(c == '\n')
			cnt_nw_line++;
	}
	printf("cnt_nw_line = %d\n", cnt_nw_line);
	
	if(cnt_nw_line < count)
		count = cnt_nw_line;
	
	cnt_nw_line = cnt_nw_line - count;
	
	rewind(fp);

	while((c = getc(fp)) != EOF)
	{
		if(c == '\n')
			cnt_nw_line--;
		if(cnt_nw_line == 0)
			break; 
	}
	
	while((c = getc(fp)) != EOF)
		putc(c, stdout);


	fclose(fp);	
	return 0;
}
