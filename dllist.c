/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:05:36 by dbotova           #+#    #+#             */
/*   Updated: 2017/04/27 18:05:37 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

t_db *new_node(void)
{
	t_db *new = (t_db*)malloc(sizeof(t_db));
	new->next = NULL;
	new->prev = NULL;
	new->name = NULL;
	new->age = NULL;
	new->school = NULL;
	new->name_len = 0;
	new->age_len = 0;
	new->school_len = 0;
	new->id = 0;

	return (new);
}

void free_node(t_db *node)
{
	SMART_FREE(node->name);
	SMART_FREE(node->age);
	SMART_FREE(node->school);
	node->next = NULL;
	node->prev = NULL;
	SMART_FREE(node);
}

void free_db(t_db **db)
{
	if (!*db)
		return ;
	free_db(&(*db)->next);
	free_node(*db);
}

void add_node(t_db **db, char *name, char *age, char *school)
{
	if (!*db)
	{
		(*db) = new_node();
		(*db)->name = strdup(name);
		(*db)->age = strdup(age);
		(*db)->school = strdup(school);
		(*db)->name_len = strlen((*db)->name);
		(*db)->age_len = strlen((*db)->age);
		(*db)->school_len = strlen((*db)->school);
		(*db)->id = 0;
		return ;
	}
	while ((*db)->next)
		db = &(*db)->next;
	(*db)->next = new_node();
	(*db)->next->prev = (*db);
	(*db)->next->name = strdup(name);
	(*db)->next->age = strdup(age);
	(*db)->next->school = strdup(school);
	(*db)->next->name_len = strlen((*db)->name);
	(*db)->next->age_len = strlen((*db)->age);
	(*db)->next->school_len = strlen((*db)->school);
	(*db)->next->id = (*db)->id + 1;
}
