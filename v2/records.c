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

	for (unsigned int i = 0; i < db->count; i++)
		printf("|%-19s", db->tabs[i].name);
	printf("|\n");
	print_records(db);
	TAB_DELIMETR;
}

void print_records(t_db *db)
{
	for (unsigned int i = 0; i < db->last_id; i++)
	{
		for (unsigned int j = 0; j < db->count; j++)
			printf("|%-19s", db->tabs[j].data[i].data);
		printf("|\n");
	}
	printf("|\n");
}

void create_record(t_db *db)
{
	char *tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);
	char *data = (char*)malloc(sizeof(char) * BUFF_LEN);
	
	printf("Enter table name: ");
	scanf("%s", tab_name);
	printf("Enter data: ");
	scanf("%s", data);

	unsigned int new_hash = hash(tab_name);

	add_cell(&db->tabs[new_hash], db->last_id, data);

	SMART_FREE(tab_name);
	SMART_FREE(data);
}
