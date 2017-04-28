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
	new->tabs = NULL;
	new->last_id = -1;

	return (new);
}

t_cell *new_cell(int id, char *data)
{
	t_cell *new = (t_cell*)malloc(sizeof(t_cell));
	memset(&new->data, 0, BUFF_LEN);
	new->data = strdup(data);
	new->id = id;

	return (new);
}

t_tab *new_tab(char *name)
{
	t_tab *new = (t_tab*)malloc(sizeof(t_tab));
	memset(&new->name, 0, BUFF_LEN);
	new->name = strdup(name);
	size = DICTIONARY_SIZE;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}

void add_tab(t_db *db, char *name)
{
	db->last_id += 1;
	t_tab *cur = db->tabs;
	if (!cur)
	{
		db->tabs = new_tab(name);
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = new_tab(name);
}
