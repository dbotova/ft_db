#include "ft_db.h"

static int db_len(t_db *db)
{
	int size = 0;

	while(db)
	{
		size += sizeof(db->name_len);
		size += sizeof(db->age_len);
		size += sizeof(db->school_len);
		size += db->name_len;
		size += db->age_len;
		size += db->school_len;
		db = db->next;
	}
	return (size);
}

void serialize_db(t_db *db, char *filename)
{
	FILE *fp;
	char *buffer = NULL;
	unsigned int len = db_len(db);
	buffer = (char *)malloc(sizeof(len));
	int seeker = 0;

	while(db != 0)
	{
		memcpy(&buffer[seeker], &db->name_len, sizeof(db->name_len));
		seeker += sizeof(db->name_len);

		memcpy(&buffer[seeker], &db->age_len, sizeof(db->age_len));
		seeker += sizeof(db->age_len);

		memcpy(&buffer[seeker], &db->school_len, sizeof(db->school_len));
		seeker += sizeof(db->school_len);

		memcpy(&buffer[seeker], db->name, db->name_len);
		seeker += db->name_len;

		memcpy(&buffer[seeker], db->age, db->age_len);
		seeker += db->age_len;

		memcpy(&buffer[seeker], db->school, db->school_len);
		seeker += db->school_len;

		db = db->next;
	}
	
	asprintf(&filename, "%s%s", "./storage/", filename);
	fp = fopen(filename, "wb+");
	fwrite(buffer, len, 1, fp);
	fclose(fp);
	free(buffer);
}