#include "header.h"

NODE *insert_node_pos(NODE * head, int data, int pos, int count)
{

	if(pos == 1){
		return insert_node_front(head, data);
	}

	if(pos == count + 1){
		return insert_node_rear(head, data);
	}

    NODE *new_node = NULL;

    if (NULL == (new_node = create_node(data))) {
		perror("node creation error");
		return NULL;
    }

	NODE *temp = NULL;

	pos--;
	temp = head;

	while(--pos){
		temp = temp -> r_link;
	}

	NODE *next = NULL;

	next = temp -> r_link;
	temp -> r_link = new_node;
	new_node -> l_link = temp;
	new_node -> r_link = next;
	next -> l_link = new_node;

	return head;
}
