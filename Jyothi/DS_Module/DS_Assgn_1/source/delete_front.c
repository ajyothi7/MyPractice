#include "header.h"

NODE * delete_front(NODE * head)
{
	if(head == NULL){
		perror("list empty");
		return NULL;
	}

	if(head -> r_link == head){
		return NULL;
	}

	NODE *temp = NULL;
	NODE *base = NULL;
	
	base = head;
	
	head = head -> r_link;
	temp = head;

	while(temp -> r_link != base)
		temp = temp -> r_link;

	temp -> r_link = head;
	head -> l_link = temp;

	return head;
}
