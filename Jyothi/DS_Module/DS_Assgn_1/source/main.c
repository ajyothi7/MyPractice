#include "header.h"

int main(void)
{
	M_NODE *m_head = NULL;
	char *input = NULL;

	input = allocate_space(input);

	while(1){
		
		printf("===============================MAIN MENU====================================\n"
				"1. insert\n"
				"2. delete\n"
				"3. search\n"
				"4. display\n"
				"5. exit\n"
				"enter your choice:\n");
		
		int choice = my_atoi(read_input(input));
		validate_int(choice);
		
		switch(choice){
			
			case 1: if(NULL == (m_head = list_info(m_head, choice))){
						perror("insertion error");

						break;
					}

					break;
			
			case 2: if(NULL == (m_head = list_info(m_head, choice))){
						perror("deletion error");

						break;
					}

					break;
		
			case 3: if(NULL == (m_head = list_info(m_head, choice))){
						perror("search error");

						break;
					}

					break;

			case 4: if(NULL == (m_head = list_info(m_head, choice))){
						perror("display error");

						break;
					}

					break;

			case 5:	free(input);
					exit(EXIT_SUCCESS);

			default:printf("invalid choice\n");
		}
	}
}
