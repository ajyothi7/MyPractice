#include "header.h"

NODE *createnode( void)
{
	NODE *new = NULL;
		
	new = (NODE *) malloc( sizeof( NODE));
	if( new == NULL)
		hndlr("malloc error in createnode")
	return new;

}
char *sstrdup( char *s)
{
	char *p = NULL;
	
	p = (char *) malloc( strlen(s) + 1);
	if(p == NULL)
		hndlr("malloc err in strdup");
	strcpy(p, s);

	return p;	
}

NODE *addnode( NODE *root, char *w , int linenum)
{
	int cond;
	
	if( root == NULL) {
		root = createnode();
		root->word = sstrdup(w);
		root->count = 1;
		root->left= root->right = NULL;
	}	
	else if(( cond = strcmp ( w, root->word)) == 0)
		{
			root->count++;
		}
	else if( cond < 0)
		root->left = addnode(root->left, w, linenum);
	else
		root->right = addnode(root->right, w, linenum);

	return root;	
}

void put_node( NODE *root, int *num, NODE *arry)
{
	if( root != NULL) {
		
		put_node( root->left, num, arry);
		arry[(*num)++] = *root;
		put_node(root->right, num, arry);	
	}

}
void print_arry( int num, NODE *arry)
{
	int i = 0;	
	for( i= num -1; i >= 0; i--)	
		printf("'%s' occured %d times\n", arry[i].word, arry[i].count);
}
void sort_arry( int num, NODE *arry)
{	
	NODE temp;
	int index = 0;
	int j;
	for( index = 0; index < num - 1  ; index ++)
		for( j = 0; j < num - index-1 ; j++)
			if( arry[j].count > arry[j+1].count)
			{	
				temp = arry[j];
				arry[j] = arry[j+1];
				arry[j+1] = temp;
			}
}


