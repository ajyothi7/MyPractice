#include "header.h"

static int top = -1;

int main(void)
{

	char *input = NULL;
	int choice;
	int data;

	input = allocate_space(input);

	while(1){
		
		printf("1. push\n"
				"2.pop\n"
				"3.display\n"
				"4.exit\n"		
				"enter your choice:");
		input = read_input(input);
		if(-1 == (choice = my_atoi(input))){
			choice = 5;
		}
		validate_int(choice);

		switch(choice){
			
			case 1: printf("enter the element to be inserted:\n");
					input = read_input(input);
					if(-1 == (data = my_atoi(input))){
						break;
					}
					validate_int(data);

					top = push(data, top);

					if(top >= 0){
						printf("element added successfully\n");
					}

					else{
						printf("failed to push element to stack\n");
					}
				
					break;

			case 2: top = pop(top);

					if(top){
						printf("element deleted\n");
					}

					else{
						printf("deletion failed\n");
					}

					break;

			case 3: if(display(top) == 0){
						printf("no elements to display\n");
					}
					break;

			case 4: free(input);
					exit(EXIT_FAILURE);

			default: printf("invalid choice\n");
		}	
	}
}
