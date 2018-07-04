#include "header.h"

NODE * delete_pos(NODE *head, int pos, int count)
{
	NODE *temp;
	NODE *prev;
	NODE *next;

	if(pos == 1)
		return delete_front(head);

	if(pos == (count + 1)){
		return delete_rear(head);
	}

	temp = head;

	while(--pos){
		temp = temp -> r_link;
	}

	next = temp -> r_link;
	prev = temp -> l_link;

	next -> l_link = prev;
	prev -> r_link = next;

	return head;
}
