/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_db.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 19:54:39 by dbotova           #+#    #+#             */
/*   Updated: 2017/04/24 19:54:40 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	init_db(t_db *database, char *db_name)
{
	database = (t_db *)malloc(sizeof(t_db));
	database->size = 0;
	strcat(database->name, db_name);
}

void	add_tab(t_db *database, char *tab_name)
{
	database->size += 1;
	strcat(database->tables[database->size - 1].name, tab_name);
	database->tables[database->size -1].last_id = 0;
	printf("THERE\n");
}

void	add_cells(t_db *database, int pos, int id, char *data)
{
	int idx;

	idx = database->tables[pos].size++;
	if (id > database->tables[pos].last_id)
		database->tables[pos].last_id++;
	database->tables[pos].cells[idx - 1].id = id;
	strcat(database->tables[pos].cells[idx - 1].data, data);
}


