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

void deserialize_db(t_db *db, char *path)
{
	FILE *fp;
	unsigned int len = file_size(path);
	unsigned int done = 0;
	char *name = NULL;
	char *age = NULL;
	char *school = NULL;
	int name_len = 0;
	int age_len = 0;
	int school_len = 0;
	int id = 0;

	fp = fopen(path, "rb");
	if (!fp)
		return ;
	while (done < len)
	{
		// read the sizes of fields
		fread(&id, sizeof(int), 1, fp);
		fread(&name_len, sizeof(int), 1, fp);
		fread(&age_len, sizeof(int), 1, fp);
		fread(&school_len, sizeof(int), 1, fp);

		//allocate memory
		name = (char *)malloc(sizeof(char) * name_len + 1);
		age = (char *)malloc(sizeof(char) * age_len + 1);
		school = (char *)malloc(sizeof(char) * school_len + 1);

		//read data for fields
		fread(name, name_len, 1, fp);
		fread(age, age_len, 1, fp);
		fread(school, school_len, 1, fp);

		done += name_len + age_len + school_len;
		done += sizeof(name_len) + sizeof(age_len) + sizeof(school_len) + sizeof(id);
		add_node(&db, name, age, school);
		
		SMART_FREE(name);
		SMART_FREE(age);
		SMART_FREE(school);
	}
	fclose(fp);
}
