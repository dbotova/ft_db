#include "ft_db.h"

t_db *create_record(t_db *db)
{
	char *name = (char*)malloc(sizeof(char) * BUFF_LEN);
	char *age = (char*)malloc(sizeof(char) * BUFF_LEN);
	char *school = (char*)malloc(sizeof(char) * BUFF_LEN);

	printf("Enter new name: ");
	scanf("%s", name);
	printf("Enter age: ");
	scanf("%s", age);
	printf("Enter school: ");
	scanf("%s", school);

	add_node(&db, name, age, school);

	SMART_FREE(name);
	SMART_FREE(age);
	SMART_FREE(school);

	return (db);
}
