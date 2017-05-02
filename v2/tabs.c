#include "ft_db.h"

void create_tab(t_db *db)
{
	char *name = (char*)malloc(sizeof(char) * BUFF_LEN);

	printf("Enter a name: \n");
	scanf("%s", name);
	add_tab(db, name);

	SMART_FREE(name);
}