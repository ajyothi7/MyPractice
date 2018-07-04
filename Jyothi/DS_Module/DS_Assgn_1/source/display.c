#include "header.h"

void display(NODE *head)
{
	if (head == NULL) {
    	perror("list empty\n");
	}

	else {

		NODE *temp = NULL;
    	temp = head;

    	printf("%d\t", temp->data);
    	while (temp->r_link != head) {
			temp = temp->r_link;
			printf("%d\t", temp->data);
    	}
		printf("\n");
	}
}
