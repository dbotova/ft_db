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
	FILE *filePtr;
	unsigned int len = file_size(path);
	unsigned int done = 0;

	filePtr = fopen(path, "rb");
	while (done < len)
	{
		// read the sizes of fields
		fread(&db->name_len, sizeof(int), 1, filePtr);
		fread(&db->age_len, sizeof(int), 1, filePtr);
		fread(&db->school_len, sizeof(int), 1, filePtr);

		//allocate memory
		db->name = (char *)malloc(sizeof(char) * db->name_len + 1);
		db->age = (char *)malloc(sizeof(char) * db->age_len + 1);
		db->school = (char *)malloc(sizeof(char) * db->school_len + 1);

		//read data for fields
		fread(db->name, db->name_len, 1, filePtr);
		fread(db->age, db->age_len, 1, filePtr);
		fread(db->school, db->school_len, 1, filePtr);

		done += 3 * sizeof(int) + db->name_len + db->age_len + db->school_len;
		if (done < len)
		{
			db->next = (t_db*)malloc(sizeof(t_db));
			db = db->next;
			db->name = NULL;
			db->age = NULL;
			db->school = NULL;
			db->next = NULL;
		}
	}
	fclose(filePtr);
}