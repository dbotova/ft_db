/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:49:48 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/04 17:49:49 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static long long		saveTab(t_db *db, char *tab_name)
{
	int flag = 0;
	long long i;
	
	printf("Enter table name: ");
	while (1)
	{
		i = 0;
		if (read_input(&tab_name) == -1)
			return (-1);
		unsigned int key = hash(tab_name);
		if (db->map[key].name[0] != 0 && !strcmp(db->map[key].name, tab_name))
		{
			i = db->map[key].index;
			flag = 1;
			break ;
		}
		else 
			printf("Invalid table name, please try again...\n");
	}
	return (i);
}

void add_record_to_tab(t_db *db)
{
	char *tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);
	char *data = (char*)malloc(sizeof(char) * BUFF_LEN);
	unsigned int id = 0;
	long long i;

	i = saveTab(db, tab_name);
	if (!i)
		return ;
	printf("Enter data: ");
	read_input(&data);
	printf("Enter id (0 for new record): ");
	scanf("%u", &id);
	
	if (id == 0)
		db->last_id++;
	add_cell(db, id != 0 ? id : db->last_id, data, i);

	SMART_FREE(tab_name);
	SMART_FREE(data);
}
