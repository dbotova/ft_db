/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 19:30:37 by dbotova           #+#    #+#             */
/*   Updated: 2017/04/24 19:30:39 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"
#define NAMES "names.txt"
#define AGE "age.txt"
#define SCHOOL "school.txt"

void read_file(t_db	*db)
{
	t_db *cur = db;
	FILE *names = fopen(NAMES, "r");
	FILE *ages = fopen(AGE, "r");
	FILE *schools = fopen(SCHOOL, "r");
	if (names == NULL || ages == NULL || schools == NULL)
		exit(EXIT_FAILURE);

	size_t len = 0;

	cur->name = NULL;
	cur->age = NULL;
	cur->school = NULL;
	getline(&cur->name, &len, names);
	cur->name_len = strlen(cur->name) - 1;
	cur->name[cur->name_len] = 0;
	getline(&cur->school, &len, schools);
	cur->school_len = strlen(cur->school) - 1;
	cur->school[cur->school_len] = 0;
	getline(&cur->age, &len, ages);
	cur->age_len = strlen(cur->age) - 1;
	cur->age[cur->age_len] = 0;

	cur->next = (t_db*)malloc(sizeof(t_db));
	cur = cur->next;
	cur->name = NULL;
	cur->age = NULL;
	cur->school = NULL;
	getline(&cur->name, &len, names);
	cur->name_len = strlen(cur->name) - 1;
	cur->name[cur->name_len] = 0;
	getline(&cur->school, &len, schools);
	cur->school_len = strlen(cur->school) - 1;
	cur->school[cur->school_len] = 0;
	getline(&cur->age, &len, ages);
	cur->age_len = strlen(cur->age) - 1;
	cur->age[cur->age_len] = 0;

	cur->next = (t_db*)malloc(sizeof(t_db));
	cur = cur->next;
	cur->name = NULL;
	cur->age = NULL;
	cur->school = NULL;
	getline(&cur->name, &len, names);
	cur->name_len = strlen(cur->name) - 1;
	cur->name[cur->name_len] = 0;
	getline(&cur->school, &len, schools);
	cur->school_len = strlen(cur->school) - 1;
	cur->school[cur->school_len] = 0;
	getline(&cur->age, &len, ages);
	cur->age_len = strlen(cur->age) - 1;
	cur->age[cur->age_len] = 0;

	fclose(names);
	fclose(ages);
	fclose(schools);

}

int db_len(t_db *db)
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

void serialize_db(t_db *db)
{
	FILE *filePtr;
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
	filePtr = fopen("db.data", "wb+");
	fwrite(buffer, len, 1, filePtr);
	fclose(filePtr);
	free(buffer);
}

int file_size(char *path)
{
	struct stat buffer;
	int size;

    if(stat(path, &buffer) < 0)
    	perror(path);
    else
    	size = buffer.st_size;
    return (size);
}

void deserialize_db(t_db *db)
{
	FILE *filePtr;
	unsigned int len = file_size("./db.data");
	unsigned int done = 0;

	filePtr = fopen("./db.data", "rb");
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

void free_list(t_db *db)
{
	t_db *tmp = NULL;

	while(db)
	{
		tmp = db;
		db = db->next;
		free(tmp->name);
		free(tmp->age);
		free(tmp->school);
		free(tmp);
	}
	db = NULL;
}

void print_db(t_db *cur)
{
	int i = 1;
	while (cur)
	{
		printf("\nStudent #%d\n", i++);
		printf("Name: %s\n", cur->name);
		printf("Age: %s\n", cur->age);
		printf("School: %s\n", cur->school);
		cur = cur->next;
	}
}

int main ()
{
	t_db *db = (t_db*)malloc(sizeof(t_db));
	// db->name = "Dasha";
	// db->age = "30";
	// db->school = "42";
	// db->name_len = strlen(db->name);
	// db->age_len = strlen(db->age);
	// db->school_len = strlen(db->school);
	// db->next = NULL;
	
	// //read_file(db);
	// print_db(db);

	// //dump to file
	// serialize_db(db);
	
	// free_list(db);

	// read from file
	//db = (t_db*)malloc(sizeof(t_db)); 
	db->name = NULL;
	db->age = NULL;
	db->school = NULL;
	db->next = NULL;

	printf("\nREAD FROM FILE TO LIST\n");
	deserialize_db(db);
	print_db(db);

	t_db *cur = db;
	while (cur->next)
		cur = cur->next;
	cur->next = (t_db*)malloc(sizeof(t_db));
	cur = cur->next;
	cur->name_len = 11;
	cur->age_len = 2;
	cur->school_len = 4;
	cur->name = "Vasya Pupkin";
	cur->age = "20";
	cur->school = "none";

	printf("\nPRINT AFTER UPDATE\n");
	print_db(db);

	// //dump to file
	serialize_db(db);
	
	//free_list(db);

	// read from file
	t_db *db_1 = (t_db*)malloc(sizeof(t_db));
	db_1->name = NULL;
	db_1->age = NULL;
	db_1->school = NULL;
	db_1->next = NULL;

	printf("\nREAD FROM FILE TO LIST AFTER UPDATE 2\n");
	deserialize_db(db_1);
	print_db(db_1);
	//free_list(db_1);

	return (0);
}
