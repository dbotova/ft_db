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

t_db *deserialize_db(t_db *db, char *path)
{
	FILE *fp;
	
	fp = fopen(path, "rb");
	if (!fp)
		return NULL;
	
	if (!db)
		db = init_db();

	fread(db, sizeof(t_db), 1, fp);

	fclose(fp);
	return (db);
}
