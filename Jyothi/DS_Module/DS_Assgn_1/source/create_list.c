#include "header.h"

NODE *create_list(NODE *head) 
{
    int data;
	int count = 0;
    char *input = NULL;

    input = allocate_space(input);

    while (1) {

	printf("1. insert rear\n"
			"2. insert front\n"
	       	"3. insert at given position\n"
			"4. insert before value\n"
			"5. insert after value\n"
	       	"6. delete rear\n"
	       	"7. delete front\n"
	       	"8. delete at given postion\n"	   
	   		"9. search\n"
	       	"10. display\n" 
		   	"11. exit\n" 
		   	"enter your choice:");

	int choice = my_atoi(read_input(input));
	validate_int(choice);

	int position;
	int value;

		switch (choice) {

			case 1: printf("enter the element to be inserted\n");
					data = my_atoi(read_input(input));
					validate_int(data);

					if(NULL == (head = insert_node_rear(head, data))){
						perror("insertion failed");
						break;
					}

					printf("insertion success\n");

					count++;

					break;

			case 2:	printf("enter the element to be inserted\n");
			        data = my_atoi(read_input(input));
					validate_int(data);				

					if(NULL == (head = insert_node_front(head, data))){
						perror("insertion failed");
						break;
					}									

					printf("insertion success\n");
					
					count++;
					
					break;
 
			case 3:	printf("enter the position\n");
					position = my_atoi(read_input(input));
					validate_int(position);

					if(position > (count + 1) || position < 0){
						perror("invalid position");
						break;
					}

					printf("enter the element to be inserted\n");
			        data = my_atoi(read_input(input));
					validate_int(data);		
					
					if(NULL == (head = insert_node_pos(head, data, position, count))){
						perror("insertion failed");
						break;
					}									

					printf("insertion success\n");
					
					count++;
					
					break;

			case 4:	printf("enter the value\n");
			        value = my_atoi(read_input(input));
					validate_int(value);

					printf("enter the element to be inserted\n");
			        data = my_atoi(read_input(input));
					validate_int(data);	

					if(NULL == (head = insert_before_value(head, value, data, count))){
						perror("insertion failed");
						break;
					}									
					
					count++;

					break;

			case 5:	printf("enter the value\n");
			        value = my_atoi(read_input(input));
					validate_int(value);

					printf("enter the element to be inserted\n");
			        data = my_atoi(read_input(input));
					validate_int(data);	

					if(NULL == (head = insert_after_value(head, value, data, count))){
						perror("insertion failed");
						break;
					}									
					
					count++;

					break;

			case 6: if(NULL == (head = delete_rear(head)) && ((count - 1) == 0)){
						printf("deletion success");

						count--;

						break;
					}
					
					if(head == NULL){
						perror("deletion failed");

						break;
					}

					printf("deletion successful\n");
					
					count--;

					break;
	
			case 7: if(NULL == (head = delete_front(head)) && ((count - 1) == 0)){
						printf("deletion success");

						count--;

						break;
					}
					
					if(head == NULL){
						perror("deletion failed");

						break;
					}

					printf("deletion successful\n");
					
					count--;

					break;
			
			case 8: printf("enter the position\n");
					position = my_atoi(read_input(input));
					validate_int(position);
					

					if(position > count || position < 0){
						perror("invalid position");
						break;
					}

					if(NULL == (head = delete_pos(head, position, count)) && ((count - 1) == 0)){
						printf("deletion success");

						count--;

						break;
					}
					
					if(head == NULL){
						perror("deletion failed");

						break;
					}

					printf("deletion successful\n");
					
					count--;

					break;

			case 9: printf("enter the element to be searched:\n");
					data = my_atoi(read_input(input));
					validate_int(data);
					
					if((position = search_node(head, data)) > 0){
						printf("search successful\n"
								"element found at position = %d\n", position);
					}

					else if(position == -1){
						perror("unsuccessful search\n");
					}

					else
						printf("no such element\n");

					break;

			case 10:display(head);
					break;

			case 11: free(input);
					return head;

			default: printf("invalid choice\n");
		}
	}
}
