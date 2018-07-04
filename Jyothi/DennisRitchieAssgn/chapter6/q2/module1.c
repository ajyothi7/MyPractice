#include "header.h"

int flag = 0;

//Dynamically allocate memory to a new NODE
NODE *createnode( void)
{
	NODE *new = NULL;
		
	new = (NODE *) malloc( sizeof( NODE));
	if( new == NULL)
		hndlr("malloc error in createnode")
	return new;

}
/*copy the string pointed by s to a memory location created using the 
	malloc with the size of the s */
char *sstrdup( char *s)
{
	char *p = NULL;
	
	p = (char *) malloc( strlen(s) + 1);
	if(p == NULL)
		hndlr("malloc err in strdup");
	strcpy(p, s);

	return p;	
}
/* compare starting n_char characters between the string sstr and string
	 in the NODE pointed by word */
int strcmp_n(char * sstr, NODE *root, int n_char )
{

	int count = 0;
	char *dstr = root->word;
	char *temp = sstr;
	while( *sstr == *dstr )
	{	
		if( *sstr == '\0')
			break;
		sstr++;
		dstr++;
		count++;
	}

	if( count >= n_char) {
		flag = 1;
		root->identical = 1;
	}
	else
		flag = 0;
	return (strcmp(temp,root->word));
}

// Adding a node to the binary tree 
NODE *addnode( NODE *root, char *w , int n_char)
{
	int cond;

	if( root == NULL) {
		root = createnode();
		root->word = sstrdup(w);
		if( flag == 0 )
			root->identical = 0;
		else
			{
				flag = 0;
				root->identical = 1;
			}
		root->left= root->right = NULL;
	}	
	else if(( cond = strcmp_n( w, root, n_char)) < 0)
		root->left = addnode(root->left, w, n_char);
	else if( cond > 0)
		root->right = addnode(root->right, w, n_char);
	return root;	
}

void put_node( NODE *root)
{
	if( root != NULL) {
		
		put_node( root->left);
		if( root->identical == 1)
			printf("%s\n", root->word);
		put_node(root->right);	
	}

}

