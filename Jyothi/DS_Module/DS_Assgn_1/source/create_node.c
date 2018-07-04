#include "header.h"

NODE *create_node(int data)
{
	NODE *new_node = NULL;

	if(NULL == (new_node = (NODE *)malloc(sizeof(NODE)))){
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node -> data = data;
	new_node -> r_link = NULL;
	new_node -> l_link = NULL;

	return new_node;
}
