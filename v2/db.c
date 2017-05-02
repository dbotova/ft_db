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

	return (new);
}

void new_cell(t_cell *new, unsigned int id, char *data)
{
	strcat(new->data, data);
	new->id = id;
}

void new_tab(t_tab *new, char *new_name)
{
	strcat(new->name, new_name);
}

void add_tab(t_db *db, char *name)
{
	db->last_id += 1;
	
	unsigned int new_hash = hash(name);
	if (db->tabs[new_hash].name[0] != 0 && new_hash < DICTIONARY_SIZE)
		new_hash++;
	new_tab(&db->tabs[new_hash], name);
	db->count++;

}

void add_cell(t_tab *tab, unsigned int id, char *data)
{
	new_cell(&tab->data[id - 1], id, data);
	tab->count++;
}
