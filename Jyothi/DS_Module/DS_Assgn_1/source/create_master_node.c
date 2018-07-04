#include "header.h"

M_NODE *create_master_node(M_NODE *m_new_node)
{
	if(NULL == (m_new_node = (M_NODE *)malloc(sizeof(M_NODE)))){
		perror("malloc failed");

		return NULL;
	}
	
	m_new_node -> m_node = NULL;
	m_new_node -> m_rlink = NULL;
	m_new_node -> m_llink = NULL;
/*
	if(NULL == (m_new_node -> m_node = insert_list(m_new_node -> m_node))){
		return NULL;
	}
*/
	return m_new_node;
}
