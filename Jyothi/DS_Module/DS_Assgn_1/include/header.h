#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 256

struct node
{
	int data;
	struct node *r_link;
	struct node *l_link;
};

typedef struct node NODE;

struct master_node{
	NODE *m_node;
	struct master_node *m_rlink;
	struct master_node *m_llink;
};

typedef struct master_node M_NODE;

NODE *create_node(int );
NODE *insert_node_rear(NODE *, int);
NODE *insert_node_front(NODE *, int);
NODE *insert_node_pos(NODE *, int, int, int);
NODE *delete_rear(NODE *);
NODE *delete_front(NODE *);
NODE *delete_pos(NODE *, int, int);
int search_node(NODE *,int);
char * allocate_space(char *);
int my_atoi(char *);
char * read_input(char *);
void validate_int(int );
M_NODE *create_master_node(M_NODE *);
NODE *create_list(NODE *);
M_NODE *insert_master_node(M_NODE *, M_NODE *);
void display(NODE *);
void m_display(M_NODE *);
NODE *insert_before_value(NODE *, int, int, int);
NODE *insert_after_value(NODE *, int, int, int);
M_NODE *list_info(M_NODE *, int);
M_NODE *insert_list(M_NODE *);
M_NODE *delete_list(M_NODE *);
