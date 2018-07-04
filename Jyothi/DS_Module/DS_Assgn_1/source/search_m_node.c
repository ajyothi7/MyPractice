#include "header.h"

int search_m_node(M_NODE *m_head, int key)
{
	if(m_head == NULL) {
		perror("list empty");
					return -1;
						}
