#include "header.h"

NODE *delete_rear(NODE *head)
{
	if(head == NULL){
		perror("list empty");
		return NULL;
	}

	if(head -> r_link == head){
		return NULL;
	}
	NODE *temp = NULL;
	NODE *prev = NULL;

	temp = head;

	while(temp -> r_link != head){
		prev = temp -> l_link;
		temp = temp -> r_link;
	}

	prev -> r_link = head;
	head -> l_link = prev;

	return head;
}
