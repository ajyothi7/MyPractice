#include "header.h"

void m_display(M_NODE *m_head)
{
	M_NODE *temp = NULL;
	int i = 1;

	if(m_head == NULL)
	{
		perror("List empty");
	}

	else{
		temp = m_head;

		printf("Displaying 1st sublist:\n");
		display(temp -> m_node);

		temp = temp -> m_rlink;
		i++;

		while(temp != m_head)
		{
			printf("Displaying %d list..\n",i);
			display(temp -> m_node);
			temp = temp -> m_rlink;
			i++;
		}

	}
}
