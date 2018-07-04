#include "header.h"

NODE *insert_after_value(NODE * head, int value, int data, int count)
{
    if (head == NULL) {
	perror("list does not exist");

	return NULL;
    }

    NODE *temp = head;

    int pos = 1;

    if (temp->data == value) {
		return insert_node_pos(head, data, pos + 1, count);
    }

	pos++;
	temp = temp -> r_link;
    while ((temp != head) && (temp->data != value)) {
		temp = temp->r_link;
		pos++;
    }

    if (temp->data == value)
		return insert_node_pos(head, data, pos + 1, count);

    return NULL;
}
