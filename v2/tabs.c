#include "ft_db.h"

void create_tab(t_db *db)
{
	char *name = (char*)malloc(sizeof(char) * BUFF_LEN);

	printf("Enter a name: \n");
	scanf("%s", name);
	add_tab(db, name);

	SMART_FREE(name);
}

void delete_tab(t_db *db)
{
	char *tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);

	printf("Enter a name: \n");
	scanf("%s", tab_name);

	unsigned int i = 0;
	while (strcmp(db->tabs[i].name, tab_name) != 0) i++;

	memset(&db->tabs[i], 0, sizeof(t_tab));
	db->count--;

	SMART_FREE(tab_name);
}