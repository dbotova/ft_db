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

unsigned int db_len(t_db *db)
{
	unsigned int size = 0;

	while(db)
	{
		size += 3 * sizeof(int); // 3 variable for len
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
		memcpy(&buffer[seeker], &db->name_len, sizeof(int));
		seeker += sizeof(int);

		memcpy(&buffer[seeker], &db->age_len, sizeof(int));
		seeker += sizeof(int);

		memcpy(&buffer[seeker], &db->school_len, sizeof(int));
		seeker += sizeof(int);

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
	unsigned int size;

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
		printf("name_len %d age_len %d school_len %d \n", db->name_len, db->age_len, db->school_len);

		//allocate memory
		db->name = (char *)malloc(sizeof(char) * db->name_len);
		db->age = (char *)malloc(sizeof(char) * db->age_len);
		db->school = (char *)malloc(sizeof(char) * db->school_len);

		//read data for fields
		fread(db->name, db->name_len, 1, filePtr);
		fread(db->age, db->age_len, 1, filePtr);
		fread(db->school, db->school_len, 1, filePtr);

		db->next = (t_db*)malloc(sizeof(t_db));
		db = db->next;
		db->name = NULL;
		db->age = NULL;
		db->school = NULL;
		done += 3 * sizeof(int) + db->name_len + db->age_len + db->school_len;
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
	db->name = NULL;
	db->age = NULL;
	db->school = NULL;
	
	read_file(db);
	print_db(db);

	//dump to file
	serialize_db(db);
	
	free_list(db);

	// read from file
	db = (t_db*)malloc(sizeof(t_db));
	db->name = NULL;
	db->age = NULL;
	db->school = NULL;

	printf("\nREAD FROM FILE TO LIST\n");
	deserialize_db(db);
	print_db(db);

	return (0);
}
