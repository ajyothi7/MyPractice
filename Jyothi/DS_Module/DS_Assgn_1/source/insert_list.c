#include "header.h"

M_NODE *insert_list(M_NODE * m_head)
{
	M_NODE *m_new_node = NULL;
	char *input = NULL;
	NODE *head = NULL;

	input = allocate_space(input);

	if(m_head == NULL){
		if(NULL == (m_new_node = create_master_node(m_new_node))){
			perror("no space available");

			return NULL;
		}

		head = m_new_node -> m_node;
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
		
		printf("for new list enter %d",list);
		int count;
		count = list;
		
		printf("enter your choice\n");
		list = my_atoi(read_input(input));

		if((list > count + 1) || (list < 0)){
			perror("invalid input");
			return m_head;
		}
		
		else if(list == count){
			if(NULL == (m_new_node = create_master_node(m_new_node))){
				perror("no space available");
				return NULL;
			}

			head = m_new_node -> m_node;
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
	int count = 0;

    while (1) {

	printf("1. insert rear\n"
	       "2. insert front\n"
	       "3. insert at given position\n"
	       "4. insert before value\n"
	       "5. insert after value\n"
	       "6. to go back\n" 
		   "enter your choice");

	int choice = my_atoi(read_input(input));
	validate_int(choice);

	int position;
	int value;

	switch (choice) {

	case 1:
	    printf("enter the element to be inserted\n");
	    data = my_atoi(read_input(input));
	    validate_int(data);

	    if (NULL == (head = insert_node_rear(head, data))) {
			perror("insertion failed");
			break;
	    }

	    printf("insertion success\n");
		display(head);

		count++;

	    break;

	case 2:
	    printf("enter the element to be inserted\n");
	    data = my_atoi(read_input(input));
	    validate_int(data);

	    if (NULL == (head = insert_node_front(head, data))) {
			perror("insertion failed");
			break;
	    }

	    printf("insertion success\n");
		display(head);

	  	count++;

	    break;

	case 3:
	    printf("enter the position\n");
	    position = my_atoi(read_input(input));
	    validate_int(position);

	    if (position > (count + 1) || position < 0) {
			perror("invalid position");
			break;
	    }

	    printf("enter the element to be inserted\n");
	    data = my_atoi(read_input(input));
	    validate_int(data);

	    if (NULL == (head = insert_node_pos(head, data, position, count))) {
			perror("insertion failed");
			break;
	    }

	    printf("insertion success\n");
		display(head);

	    count++;

	    break;

	case 4:
	    printf("enter the value\n");
	    value = my_atoi(read_input(input));
	    validate_int(value);

	    printf("enter the element to be inserted\n");
	    data = my_atoi(read_input(input));
	    validate_int(data);

	    if (NULL == (head = insert_before_value(head, value, data, count))) {
			perror("insertion failed");
			break;
	    }

	    printf("insertion success\n");
		display(head);

		count++;

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

		count++;

	    break;

	case 6:  m_new_node -> m_node = head;

			 m_head = insert_master_node(m_head, m_new_node);

			 //free(input);

			 return m_head;
	}
  }
}
