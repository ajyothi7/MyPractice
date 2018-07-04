#include "header.h"

int search_node(NODE *head, int key)
{
	if(head == NULL){
		perror("list empty");

		return -1;
	}

	NODE *temp = NULL;

	temp = head;

	if(temp -> data == key){
		return 1;
	}

	int pos = 1;
	temp = temp -> r_link;

	while(temp != head){
		if(temp -> data == key)
			return pos + 1;
 
		temp = temp -> r_link;
		pos++;
	}
	/*
	while((temp != head) && (temp -> data != key)){
			temp = temp -> r_link;
			pos++;
	}

	if(temp -> data == key)
		return pos;
*/
	return 0;
}
