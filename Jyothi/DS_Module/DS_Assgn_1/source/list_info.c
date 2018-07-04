#include "header.h"

M_NODE *list_info(M_NODE *m_head, int choice)
{
/*	if((m_head == NULL) && (choice > 1)){
		perror("list empty");

		return NULL;
	}

	else if((m_head == NULL) && (choice == 1)){
		m_head = insert_list(m_head);

		return m_head;
	}

	else{
*/
	switch(choice){
		
		case 1: m_head = insert_list(m_head);
			
				break;

		case 2: m_head = delete_list(m_head);

				break;
				
	/*	case 3: m_head = search_list(m_head);

				break;

		case 4: m_head = display_list(m_head);

				break;*/
	}

		return m_head;
	//}
}
