#include "header.h"

NODE *delete_value(NODE * head, int value, int data, int count)
{
    if (head == NULL) {
	perror("list does not exist");

	return NULL;
    }

    NODE *temp = head;
	int pos = 0;
	int count = 1;
	
	if
	while(temp -> r_link != head){
		if(temp -> data == 
		count++;
	}
	
	if((pos = search_node(temp)) > 0){
    
		return delete_pos(head, data, pos, count);

	}
    return NULL;
}
