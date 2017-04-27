#include "ft_db.h"

static int file_size(char *path)
{
	struct stat buffer;
	int size = 0;

    if(stat(path, &buffer) < 0)
    	perror(path);
    else
    	size = buffer.st_size;
    return (size);
}

void deserialize_db(t_db *db, char *path)
{
	FILE *fp;
	unsigned int len = file_size(path);
	unsigned int done = 0;

	fp = fopen(path, "rb");
	while (done < len)
	{
		// read the sizes of fields
		fread(&db->name_len, sizeof(int), 1, fp);
		fread(&db->age_len, sizeof(int), 1, fp);
		fread(&db->school_len, sizeof(int), 1, fp);

		//allocate memory
		db->name = (char *)malloc(sizeof(char) * db->name_len + 1);
		db->age = (char *)malloc(sizeof(char) * db->age_len + 1);
		db->school = (char *)malloc(sizeof(char) * db->school_len + 1);

		//read data for fields
		fread(db->name, db->name_len, 1, fp);
		fread(db->age, db->age_len, 1, fp);
		fread(db->school, db->school_len, 1, fp);

		done += 3 * sizeof(int) + db->name_len + db->age_len + db->school_len;
		if (done < len)
		{
			db->next = new_node();
		}
	}
	fclose(fp);
}