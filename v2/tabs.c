#include "ft_db.h"

void create_tab(t_db *db)
{
	char *tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);

	printf("Enter a name (0 to cancel): \n");
	read_input(&tab_name);
	if (strcmp(tab_name, "0") == 0)
	{
		SMART_FREE(tab_name);
		return ;
	}

	add_tab(db, tab_name);
	db->filled++;
	SMART_FREE(tab_name);
}

int		checkID(char *tab_name)
{
	unsigned long int i = 0;

	while (i < strlen(tab_name))
		if (!isdigit(tab_name[i++]))
			return (0);
	return (1);
}

void    deleteID(t_db *db, char *tab_name)
{
    unsigned int id;
    
    printf("Enter ID number:\n");
    while (42)
    {
    	read_input(&tab_name);
    
    	if (!checkID(tab_name))
    		printf("Invalid ID format, please try again...\n");
    	else if ((unsigned int)atoi(tab_name) > db->last_id)
    		printf("Invalid ID range, please try again...\n");
    	else
    	{
    		id = atoi(tab_name);
    		break;
    	}
    }
    for (unsigned int i = 0; i < DICTIONARY_SIZE; i++)
    {
        if (db->tabs[i].name[0] != 0)
        {
            memset(&db->tabs[i].map[hash(db->tabs[i].data[id - 1].data)], 0, sizeof(t_map));
            memset(&db->tabs[i].data[id - 1], 0, sizeof(t_cell));
        }
    }
}

void	deleteColumn(t_db *db, char *tab_name)
{
	unsigned int i = 0;

	unsigned int key = hash(tab_name);
	while (strcmp(db->map[key].name, tab_name) != 0) key++;
	while (strcmp(db->tabs[i].name, tab_name) != 0) i++;

	if (key >= DICTIONARY_SIZE || i >= DICTIONARY_SIZE)
		return ;

	memset(&db->tabs[i], 0, sizeof(t_tab));
	memset(&db->map[key], -1, sizeof(t_map));
	db->filled--;
	if (db->filled == 0)
	{
		db->last_id = 0;
		db->count = 0;
		memset(db, 0, sizeof(t_db));
	}
	SMART_FREE(tab_name);
	
}

void	validateColumnName(t_db *db, char *tab_name)
{
	int flag = 0;
	unsigned int i;

	printf("Enter column name:\n");
	while (42)
	{
		i = 0;
		read_input(&tab_name);
		while (i < db->count)
			if (!strcmp(db->tabs[i++].name, tab_name))
			{
				flag = 1;
				break;
			}
		if (flag)
			break;
		else 
			printf("Invalid column name, please try again...\n");
	}
	deleteColumn(db, tab_name);
}

void delete_tab(t_db *db)
{
	char *tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);

	printf("%-20s", "[DELETE COLUMN(1)]");
	printf("%-20s", "[DELETE ROW(2)]");
	printf("%-20s", "[CANCEL (0)]\n");

	while (42)
	{
		read_input(&tab_name);

		if (!strcmp(tab_name, "0"))
			return;
		else if (!strcmp(tab_name, "1"))
		{
			validateColumnName(db, tab_name);
			break;
		}
		else if (!strcmp(tab_name, "2"))
		{
			deleteID(db, tab_name);
			SMART_FREE(tab_name);
			break;
		}
		else
			printf("Invalid option, please try again...");		
	}
}