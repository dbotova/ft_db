/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:05:52 by dbotova           #+#    #+#             */
/*   Updated: 2017/04/27 18:05:54 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_db *deserialize_db(t_db *db, char *path)
{
	FILE *fp;
	unsigned int len = file_size(path);
	unsigned int done = 0;
	char *name = NULL;
	char *age = NULL;
	char *school = NULL;
	size_t name_len = 0;
	size_t age_len = 0;
	size_t school_len = 0;
	size_t id = 0;

	fp = fopen(path, "rb");
	if (!fp)
		return NULL;
	while (done < len)
	{
		// read the sizes of fields
		fread(&id, sizeof(int), 1, fp);
		fread(&name_len, sizeof(size_t), 1, fp);
		fread(&age_len, sizeof(size_t), 1, fp);
		fread(&school_len, sizeof(size_t), 1, fp);

		//allocate memory
		name = (char *)malloc(sizeof(char) * name_len + 1);
		name[name_len] = 0;
		age = (char *)malloc(sizeof(char) * age_len + 1);
		age[age_len] = 0;
		school = (char *)malloc(sizeof(char) * school_len + 1);
		school[school_len] = 0;

		//read data for fields
		fread(name, name_len, 1, fp);
		fread(age, age_len, 1, fp);
		fread(school, school_len, 1, fp);

		done += (name_len + 1) + (age_len + 1) + (school_len + 1) + id;
		done += sizeof(name_len) + sizeof(age_len) + sizeof(school_len) + sizeof(id);
		add_node_from_file(&db, name, age, school, id);
		
		SMART_FREE(name);
		SMART_FREE(age);
		SMART_FREE(school);
	}
	fclose(fp);
	return (db);
}
