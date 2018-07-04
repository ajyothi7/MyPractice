//stack implementation updated

#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int top = -1;	
int stack[MAX];


int main(void)
{
	char *ptr = NULL ; 
	int choice ;
	int num;
	int ele;
	int i;
	int count = 0;	

	if(NULL == (ptr = (char *) malloc ( sizeof (char) * MAX ) ) ) {
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while(1){	
		printf("Enter choice .... \n"
				"1-push\n"
				"2-pop\n"
				"3-display\n"
				"4-push n\n"
				"5-pop n\n"
				"6-exit\n"
				"7-Display top of stack\n"
				"8-Duplicate top element\n"
				"9-Swap top two elements \n");
	
		if(NULL == (fgets(ptr,MAX,stdin))){
        	perror("fgets failed\n");
        	exit(EXIT_FAILURE);
    	}

		choice = atoi (ptr);
			
		if(choice == -1){	
			printf("Invalid Input ..Enter only numbers\n");
			break;
		}
		
		switch(choice)
		{
			case 1:
					printf("Enter stack element to be pushed\n");
			
					if(NULL == (fgets(ptr,MAX,stdin))){
						perror("fgets failed\n");
						exit(EXIT_FAILURE);
					}
						
					num = atoi(ptr);

					if(num == -1){	
						printf("Invalid Input ..Enter only numbers\n");
						break;
					}		
					push(num);

					break;
	
			case 2:
					pop();
					break;

			case 3:			
					display();
					break;
	
			
			case 4:
					printf("Enter number of elements to be pushed\n");
						
					
					if(NULL == (fgets(ptr,MAX,stdin))){
						perror("fgets failed\n");
						exit(EXIT_FAILURE);
					}
					num = atoi(ptr);

					if(num == -1){	
						printf("Invalid Input ..Enter only numbers\n");
						break;
					}		
				
					for(i = 1 ; i <= num ; i++) {
			
						
					printf("Enter stack element %d : ",i);
						
						if(NULL == (fgets(ptr,MAX,stdin))){
							perror("fgets failed\n");
							exit(EXIT_FAILURE);
						}
					
						ele = atoi(ptr);

						if(ele == -1){	
							printf("Invalid Input ..Enter only numbers\n");
						break;
						}		
						push_n(ele);
					}

					break;
			case 5 : 
					printf("Enter number of elements to be popped\n");


                    if(NULL == (fgets(ptr,MAX,stdin))){
                        perror("fgets failed\n");
                        exit(EXIT_FAILURE);
                    }
                    num = atoi(ptr);

					if(num == -1){	
						printf("Invalid Input ..Enter only numbers\n");
						break;
					}
					count = display();
					if( count < num ){
						printf("Only %d elements are present..can't perform pop operation\n",count);
						break;
					}
					
					for(i = 1 ; i <= num ; i++) {
						pop_n(num);
					}
					break;
								
			case 6 : exit(0);

			case 7 :if(top == -1)
    			        printf("No elements to display\n");

    				else
				        printf("Top element of stack is %d\n", stack[top]);

					break;

			case 8 :if(top == -1)
                        printf("No elements to duplicate\n");

					else
						push(stack[top]);

					break;

			case 9 :if((top == -1) && (top == 0))
                        printf("No or less elements to swap\n");

					else
					{
						int temp = stack[top];
						stack[top] = stack[top - 1];
						stack[top - 1] = temp;
					}

					break;
						           	
			default:
					printf("Invalid Choice\n");
		}
	}

	free(ptr);
	ptr = NULL;

	return 0;
}


int display()
{
	int i;
	int count = 0;
	if(top == -1)
	{
		printf("NO elements to display\n");
	}
	else
		printf("Stack elements are \n");
		for (i = 0; i <= top; i++){
      		printf("%d\n", stack[i]);
			count++;
		}
		printf("\n");
		return count;
}



int pop()
{
	int y;
	if (top == -1)
	{
		printf("Stack underflow\n");
		return -1;
	}
	else
	{
		y = stack[top] ;
		top = top - 1 ;
		printf("Element %d is popped\n",y);
		return 0;
	}
}



int push(int x)
{

	if ( top > MAX )
	{
		printf(" Stack Overflow \n");
		exit(0);
	}
	else
	{
		top = top + 1 ;
		stack[top] = x ;
		printf("Element %d is pushed \n",x);
		return 0;
	}
}


int push_n(int x)
{
    if ( top > MAX )
    {
        printf(" Stack Overflow \n");
        exit(0);
    }
    else
        top = top + 1 ;
        stack[top] = x ;
		printf("Element %d is pushed successfully\n",x);
	return 0;
}

int pop_n()
{
    int y;
    if (top == -1 )
    {
        printf("Stack underflow..Nothing is there to pop\n");
        exit(0);
    }
    else
    {
        y = stack[top] ;
        top = top - 1 ;
        printf("Element %d is popped\n",y);
        return 0;
    }
}


