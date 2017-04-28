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
	t_tab *cur = db->tabs;

	size += sizeof(db->last_id);
	while(cur)
	{
		size += sizeof(cur->size);
		size += sizeof(cur->name);
		size += sizeof(cur->data);
		cur = cur->next;
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
	t_tab *cur = db->tabs;

	memcpy(&buffer[seeker], &db->last_id, sizeof(db->last_id));
	seeker += sizeof(int);

	while(cur)
	{
		memcpy(&buffer[seeker], cur->size, sizeof(unsigned int));
		seeker += sizeof(unsigned int);

		memcpy(&buffer[seeker], cur->name, BUFF_LEN);
		seeker += BUFF_LEN;

		cur = cur->next;
	}

	fp = fopen(filename, "wb+");
	if (!fp)
		perror("open file");
	rewind(fp);
	fwrite(buffer, len, 1, fp);
	fclose(fp);
}
