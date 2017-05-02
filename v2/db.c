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
	new->count = 0;
}

void add_tab(t_db *db, char *name)
{	
	db->count++;
	new_tab(&db->tabs[db->count - 1], name);

}

void add_cell(t_db *db, unsigned int id, char *data, unsigned int idx)
{
	new_cell(&db->tabs[idx].data[id - 1], id, data);
	if (id > db->last_id)
		db->tabs[idx].count++;
}
