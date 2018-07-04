#include "header.h"

NODE *insert_node_rear(NODE *head, int data)
{
	NODE *new_node = NULL;

	if(NULL == (new_node = create_node(data))){
		perror("node creation error");
		return NULL;
	}

	if(head == NULL){
		head = new_node;
		new_node -> l_link = head;
		new_node -> r_link = head;

		return head;
	}

	NODE *temp = NULL;

	temp = head;

	while(temp -> r_link != head){
		temp = temp -> r_link;
	}

	temp -> r_link = new_node;
	new_node -> l_link = temp;
	new_node -> r_link = head;

	return head;
}
