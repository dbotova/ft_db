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
	char *name = (char*)malloc(sizeof(char) * BUFF_LEN);

	printf("Enter a name: \n");
	scanf("%s", name);

	unsigned int new_hash = hash(name);
	if (strcmp(db->tabs[new_hash].name, name) == 0)
	{
		memset(&db->tabs[new_hash], 0, sizeof(t_tab));
		db->count--;
	}

	SMART_FREE(name);
}