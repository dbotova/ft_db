#include "ft_db.h"

t_db *new_node(t_db *node)
{
	t_db *new = (t_db*)malloc(sizeof(t_db));
	new->next = node;
	new->prev = NULL;
	new->name = NULL;
	new->age = NULL;
	new->school = NULL;
	new->name_len = 0;
	new->age_len = 0;
	new->school_len = 0;

	return (new);
}

void free_node(t_db *node)
{
	SMART_FREE(node->name);
	SMART_FREE(node->age);
	SMART_FREE(node->school);
	node->next = NULL;
	node->prev = NULL;
	SMART_FREE(node);
}