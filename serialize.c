/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:05:42 by dbotova           #+#    #+#             */
/*   Updated: 2017/04/27 18:05:44 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		size += sizeof(db->id);
		size += db->id;
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

	while(db)
	{
		memcpy(&buffer[seeker], &db->id, sizeof(db->id));
		seeker += sizeof(int);
		
		memcpy(&buffer[seeker], &db->name_len, sizeof(db->name_len));
		seeker += sizeof(size_t);

		memcpy(&buffer[seeker], &db->age_len, sizeof(db->age_len));
		seeker += sizeof(size_t);

		memcpy(&buffer[seeker], &db->school_len, sizeof(db->school_len));
		seeker += sizeof(size_t);

		memcpy(&buffer[seeker], db->name, db->name_len);
		seeker += db->name_len;

		memcpy(&buffer[seeker], db->age, db->age_len);
		seeker += db->age_len;

		memcpy(&buffer[seeker], db->school, db->school_len);
		seeker += db->school_len;

		db = db->next;
	}

	fp = fopen(filename, "wb+");
	if (!fp)
		perror("open file");
	rewind(fp);
	fwrite(buffer, len, 1, fp);
	fclose(fp);
}
