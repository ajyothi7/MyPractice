#include "header.h"

M_NODE *insert_master_node(M_NODE *m_head, M_NODE *m_new_node)
{
/*	M_NODE *m_new_node = NULL;

	if(NULL == (m_new_node = create_master_node(m_new_node))){
		perror("no space available");

		return NULL;
	}
*/
	if (m_head == NULL) {
    	m_head = m_new_node;
    	m_new_node->m_rlink = m_head;
    	m_new_node->m_llink = m_head;

    	return m_head;
	}

	M_NODE *temp = NULL;

	temp = m_head;

	while (temp -> m_rlink != m_head)
    	temp = temp -> m_rlink;

	temp -> m_rlink = m_new_node;
	m_new_node -> m_llink = temp;
	m_new_node -> m_rlink = m_head;

	return m_head;

}
