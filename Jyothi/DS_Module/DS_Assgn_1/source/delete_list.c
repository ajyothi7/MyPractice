#include "header.h"

M_NODE *insert_list(M_NODE * m_head)
{
	M_NODE *m_new_node = NULL;
	char *input = NULL;
	NODE *head = NULL;
	int count;

	input = allocate_space(input);

	if(m_head == NULL){
		perror("list empty");
		return NULL;
	}

	else{
		M_NODE *temp = m_head;
		
		printf("1. List1\n");
		temp = temp -> m_rlink;

		int list = 2;

		while(temp != m_head){
			printf("%d. List%d\n",list, list);
			temp = temp -> m_rlink;
			list++;
		}
				
		printf("enter your choice\n");
		list = my_atoi(read_input(input));

		count  = list;

		if((list > count) || (list < 0)){
			perror("invalid input");
			return m_head;
		}
	
		else{
			temp = m_head;
			while(--list){
				temp = temp -> m_rlink;
			}

			head = temp -> m_node;
		}
	}
	
	int data;
	
	NODE *cur = NULL;

	cur = head;

	count = 0;
	if(head != NULL){
		count = 1;
		while(cur -> r_link != head){
			count++;
		}
	}
    while (1) {

	printf("1. delete rear\n"
	       "2. delete front\n"
	       "3. delete at given position\n"
		   "4. delete given value\n"
	       "4. delete before value\n"
	       "5. delete after value\n"
		   "7. delete entire list\n"
	       "8. to go back\n" 
		   "enter your choice");

	int choice = my_atoi(read_input(input));
	validate_int(choice);

	int position;
	int value;

	switch (choice) {

	case 1:
	    if (NULL == (head = delete_rear(head, data))) {
			perror("deletion failed");
			break;
	    }

	    printf("deletion success\n");
		display(head);

		count--;

	    break;

	case 2:
	    if (NULL == (head = delete_front(head, data))) {
			perror("deletion failed");
			break;
	    }

	    printf("deletion success\n");
		display(head);

	  	count--;

	    break;

	case 3:
	    printf("enter the element position to be deleted from the below list\n",);
		display(head);
	    position = my_atoi(read_input(input));
	    validate_int(position);

	    if (position > (count) || position < 0) {
			perror("invalid position");
			break;
	    }

	    if (NULL == (head = delete_pos(head, data, position, count))) {
			perror("deletion failed");
			break;
	    }

	    printf("deletion success\n");
		display(head);

	    count--;

	    break;

	case 4:
	    printf("enter the value\n");
	    value = my_atoi(read_input(input));
	    validate_int(value);

	    if (NULL == (head = delete_value(head, value, data, count))) {
			perror("deletion failed");
			break;
	    }

	    printf("deletion success\n");
		display(head);

		count--;

	    break;

	case 5:
	    printf("enter the value\n");
	    value = my_atoi(read_input(input));
	    validate_int(value);

	    printf("enter the element to be inserted\n");
	    data = my_atoi(read_input(input));
	    validate_int(data);

	    if (NULL == (head = insert_after_value(head, value, data, count))) {
			perror("insertion failed");
			break;
	    }

	    printf("insertion success\n");
	    display(head);

		count--;

	    break;

	case 6:  m_new_node -> m_node = head;

			 m_head = insert_master_node(m_head, m_new_node);

			 free(input);

			 return m_head;
	}
  }
}
