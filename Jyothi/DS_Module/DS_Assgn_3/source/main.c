#include "header.h"

int main(void)
{
    char *input = NULL;
    int size;

    if(NULL == (input = (char *)malloc(sizeof(char *)))){
        perror("malloc failed");
    	exit(EXIT_FAILURE);
    }

    int index = 0;
	int choice;
	
	while(1){

	printf("1.Bubble Sort\n");
	printf("2.Selection sort\n");
	printf("3.Insertion sort\n");
	printf("4.Quick sort\n");
	printf("5.exit\n");
	printf("Enter your choice\n");
	choice = my_atoi(read_input(input));

	if((choice > 0) && (choice < 6)){ 
    	printf("enter the array size\n");
    	size = my_atoi(read_input(input));
	}
	
	int arr[size];

	switch(choice)
	{
		case 1 :
				printf("1. Bubble sort iterartive\n");
				printf("2. Bubble sort recursive\n");
				printf("Enter your choice\n");
				choice = my_atoi(read_input(input));
				switch(choice)
				{
					case 1:
							printf("enter the array elements\n");
							for(index = 0; index < size; index++){ 
								arr[index] = my_atoi(read_input(input));
							}
						
    	  					printf("before sorting\n");	
        					print_array(arr,size);		
								
							bubble_sort(arr, size);

				        	printf("after sorting\n");
       						print_array(arr, size);
							break;
				
					case 2:	
							printf("enter the array elements\n");
							for(index = 0; index < size; index++){ 
								arr[index] = my_atoi(read_input(input));
							}
	
    	  					printf("before sorting\n");	
        					print_array(arr,size);		
							
							bubble_sort_rec(arr,size);

				    	    printf("after sorting\n");
       						print_array(arr, size);
							break;

				}
				break;
		case 2:		
				printf("1. Selection sort iterartive\n");
				printf("2. Selection sort recursive\n");
				printf("Enter your choice\n");
				choice = my_atoi(read_input(input));
				switch(choice)
				{
					case 1:
							printf("enter the array elements\n");
							for(index = 0; index < size; index++){ 
								arr[index] = my_atoi(read_input(input));
							}
						
      						printf("before sorting\n");	
        					print_array(arr,size);		
						
							selection_sort(arr, size);

				        	printf("after sorting\n");
       						print_array(arr, size);
							break;
				
					case 2:	
							printf("enter the array elements\n");
							for(index = 0; index < size; index++){ 
								arr[index] = my_atoi(read_input(input));
							}

      						printf("before sorting\n");	
        					print_array(arr,size);		
						
							selection_sort_rec(arr,0,size);

				        	printf("after sorting\n");
       						print_array(arr, size);
							break;
				}
				break;
		case 3:	
				printf("1. Insertion sort iterartive\n");
				printf("2. Insertion sort recursive\n");
				printf("Enter your choice\n");
				choice = my_atoi(read_input(input));
				switch(choice)
				{
					case 1:
							printf("enter the array elements\n");
							for(index = 0; index < size; index++){ 
								arr[index] = my_atoi(read_input(input));
							}
						
      						printf("before sorting\n");	
        					print_array(arr,size);		
						
							insertion_sort(arr, size);

				        	printf("after sorting\n");
       						print_array(arr, size);
							break;
				
					case 2:	
							printf("enter the array elements\n");
							for(index = 0; index < size; index++){ 
								arr[index] = my_atoi(read_input(input));
							}

      						printf("before sorting\n");	
        					print_array(arr,size);		
						
							insertion_sort_rec(arr, size);

				        	printf("after sorting\n");
       						print_array(arr, size);
							break;
					}
					break;

		case 4:
					printf("enter the array elements\n");
					for(index = 0; index < size; index++){ 
							arr[index] = my_atoi(read_input(input));
					}

      				printf("before sorting\n");	
        			print_array(arr,size);		
						
					quick_sort_rec(arr,0,size - 1);

				    printf("after sorting\n");
       				print_array(arr, size);
						
					break;
		

		case 5: exit(EXIT_SUCCESS);

				default:
					printf("Invalid input\n");
	}
	}
}

