/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   records.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:05:24 by dbotova           #+#    #+#             */
/*   Updated: 2017/04/27 18:05:26 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void print_tabs(t_db *db)
{	
	TAB_DELIMETR;
	if (db->count == 0)
	{
		printf("|%35s%-22s|\n", "***EMPTY***", "");
		TAB_DELIMETR;
		return ;
	}

	for (unsigned int i = 0; i < DICTIONARY_SIZE; i++)
	{
		if (db->tabs[i].name[0] != 0)
			printf("|%-19s", db->tabs[i].name);
	}
	printf("|\n");
	TAB_DELIMETR;
}

void print_records(t_db *db)
{
	if (db->tabs.count != 0)
	{
		for (unsigned int i = 0; i < DICTIONARY_SIZE; i++)
		{
			if (db->tabs[i].name[0] != 0)
			{
				for (unsigned int j = 0; j < DICTIONARY_SIZE; j++)
				{
					if (db->tabs[i].data[j].data != 0)
						printf("|%-19s", db->tabs[i].data[j].data);
				}
			}
		}
	}
}

void create_record(t_db *db)
{
	char *tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);
	char *data = (char*)malloc(sizeof(char) * BUFF_LEN);
	
	printf("Enter table name: ");
	scanf("%s", tab_name);
	printf("Enter data: ");
	scanf("%s", data);

	unsigned int new_hash = hash(name);
	add_cell(db->tabs[new_hash], db->last_id, data);

	SMART_FREE(tab_name);
	SMART_FREE(data);
}
