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

void serialize_db(t_db *db, char *filename)
{
	FILE *fp;
	char *buffer = (char*)malloc(sizeof(t_db));

	memcpy(&buffer, &db, sizeof(db));

	fp = fopen(filename, "wb+");
	if (!fp)
		perror("open file");
	rewind(fp);
	fwrite(buffer, sizeof(t_db), 1, fp);
	SMART_FREE(buffer);
	fclose(fp);
}
