#include "ft_db.h"

void create_tab(t_db *db)
{
	char *tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);

	printf("Enter a name: \n");
	scanf("%s", tab_name);

	if (strcmp(tab_name, "cancel") == 0)
	{
		SMART_FREE(tab_name);
		return ;
	}

	add_tab(db, tab_name);
	SMART_FREE(tab_name);
}

void delete_tab(t_db *db)
{
	char *tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);

	printf("Enter a name: \n");
	scanf("%s", tab_name);

	if (strcmp(tab_name, "cancel") == 0)
	{
		SMART_FREE(tab_name);
		return ;
	}

	unsigned int i = 0;
	unsigned int key = hash(tab_name);
	while (strcmp(db->map[key].name, tab_name) != 0) key++;
	while (strcmp(db->tabs[i].name, tab_name) != 0) i++;

	if (key >= DICTIONARY_SIZE || i >= DICTIONARY_SIZE)
		return ;

	memset(&db->tabs[i], 0, sizeof(t_tab));
	memset(&db->map[key], -1, sizeof(t_map));
	db->count--;
	SMART_FREE(tab_name);
}