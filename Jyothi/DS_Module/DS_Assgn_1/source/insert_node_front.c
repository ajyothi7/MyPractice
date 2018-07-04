#include "header.h"

NODE *insert_node_front(NODE * head, int data)
{
    NODE *new_node = NULL;

    if (NULL == (new_node = create_node(data))) {
		perror("node creation error");
		return NULL;
    }

    if (head == NULL) {
		head = new_node;
		new_node -> l_link = head;
		new_node -> r_link = head;

		return head;
    }

	NODE *last = NULL;
	last = head;

	while(last -> r_link != head)
		last = last -> r_link;

	last -> r_link = new_node;
	new_node -> l_link = last;
	new_node -> r_link = head;
	head -> l_link = new_node;
	head = new_node;

    return head;
}
