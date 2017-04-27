#include "ft_db.h"

t_db *new_node(void)
{
	t_db *new = (t_db*)malloc(sizeof(t_db));
	new->next = NULL;
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

void free_db(t_db **db)
{
	if (!*db)
		return ;
	free_db(&(*db)->next);
	free_node(*db);
}

void add_node(t_db **db, char *name, char *age, char *school)
{
	if (!*db)
	{
		(*db) = new_node();
		(*db)->name = strdup(name);
		(*db)->age = strdup(age);
		(*db)->school = strdup(school);
		(*db)->name_len = strlen((*db)->name);
		(*db)->age_len = strlen((*db)->age);
		(*db)->school_len = strlen((*db)->school);
		return ;
	}
	add_node(&(*db)->next, name, age, school);
}