/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 07:57:15 by dbotova           #+#    #+#             */
/*   Updated: 2017/04/28 07:57:17 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

t_db *init_db(void)
{
	t_db *new = (t_db*)malloc(sizeof(t_db));
	new->last_id = 0;
	new->count = 0;
	memset(&new->map, 0, sizeof(t_map));

	return (new);
}

void new_cell(t_cell *new, unsigned int id, char *data)
{
	memset(new->data, 0, sizeof(char) * BUFF_LEN);
	strcat(new->data, data);
	new->id = id;
}

void new_tab(t_tab *new, char *new_name)
{
	strcat(new->name, new_name);
	new->count = 0;
	memset(&new->map, 0, sizeof(t_map));
}

void add_tab(t_db *db, char *name)
{	
	db->count++;
	new_tab(&db->tabs[db->count - 1], name);

	unsigned int key = hash(name);
	
	while (db->map[key].name[0] != 0) key++;

	db->map[key].index = db->count - 1;
	strcat(db->map[key].name, name);
}

void add_cell(t_db *db, unsigned int id, char *data, unsigned int idx)
{
	new_cell(&db->tabs[idx].data[id - 1], id, data);
	if (id > db->last_id)
		db->tabs[idx].count++;

	unsigned int key = hash(data);

	while (db->tabs[idx].map[key].name[0] != 0) key++;
	db->tabs[idx].map[key].index = id - 1;
	strcat(db->tabs[idx].map[key].name, data);
}
