#include "header.h"

NOISE_W noise_word[] = { {"a"},
					     {"an"},
						 {"and"},
						 {"are"}, {"as"}, {"but"},{"for"}, {"if"}, {"in"},{"is"}, {"of"}, {"the"}, {"there"}};

int noiseword( char *w)
{
	int low = 0;
	int high = N_NOISE - 1;
	int mid;
	int cond;

	while( low <= high)
	{
		mid = low + ( high - low) /2 ;
		if( (cond = strcmp(w, noise_word[mid].word)) < 0)
			high = mid -1;
		else if( cond > 0)
			low = mid +1 ;
		else
			{
			return 1;
			}
	}
	return -1;
}
	
NODE *createnode( void)
{
	NODE *new = NULL;
		
	new = (NODE *) malloc( sizeof( NODE));
	if( new == NULL)
		hndlr("malloc error in createnode")
	return new;

}

void addline( NODE *root, int linenum)
{
	LIST *temp = NULL;
	if( root->list == NULL)
	{
		temp = (LIST *) malloc( sizeof( LIST));
		if( temp == NULL)
			hndlr("malloc error in addlist")
		root->list = temp;
		temp->n_list = NULL;
		temp->line = linenum;
	}	
	else
	{
		temp = root->list;
		while( temp->n_list != NULL && temp->line != linenum)
		{
				temp = temp->n_list;
		}
		if( temp->line != linenum)
		{	
			temp->n_list = (LIST *) malloc( sizeof(LIST));
			if(temp->n_list == NULL)
				hndlr("malloc error in addline")
			(temp->n_list)->line = linenum;
			(temp->n_list)->n_list = NULL;	
	}
	}
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
	    root->list = NULL;
		addline( root, linenum);
	}	
	else if(( cond = strcmp ( w, root->word)) == 0)
		{
			root->count++;
			addline(root, linenum);
		}
	else if( cond < 0)
		root->left = addnode(root->left, w, linenum);
	else
		root->right = addnode(root->right, w, linenum);

	return root;	
}

void print_line( LIST *list)
{	
	while( list != NULL)
	{
		printf("%d  ", list->line);
		list = list->n_list;
	}
	printf("\n");	
}

void print_node( NODE *root)
{
	if( root != NULL) {
		
		print_node( root->left);
			
		printf("%s:\t",root->word);
		print_line(root->list);
		
		print_node(root->right);	
	}

}

