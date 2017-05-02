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
	if (db->count == 0)
	{
		TAB_DELIMETR;
		printf("|%35s%-22s|\n", "***EMPTY***", "");
		TAB_DELIMETR;
		return ;
	}
	for (unsigned int i = 0; i <= db->count; i++)
		printf("--------------------");
	printf("-\n");
	printf("|%-19s", "ID");
	for (unsigned int i = 0; i < DICTIONARY_SIZE; i++)
	{
		if (db->tabs[i].name[0] != 0)
			printf("|%-19s", db->tabs[i].name);
	}
	printf("|\n");
	for (unsigned int i = 0; i <= db->count; i++)
		printf("--------------------");
	printf("-\n");
	print_records(db);
}

void print_records(t_db *db)
{
	for (unsigned int i = 0; i < db->last_id; i++)
	{
		printf("|%-19u", i + 1);
		for (unsigned int j = 0; j < DICTIONARY_SIZE; j++)
		{
			if (db->tabs[j].name[0] != 0)
				printf("|%-19s", db->tabs[j].data[i].data[0] != 0 ? db->tabs[j].data[i].data : "(none)");
		}
		printf("|\n");
	}
	for (unsigned int i = 0; i <= db->count; i++)
		printf("--------------------");
	printf("-\n");
}

void add_record_to_tab(t_db *db)
{
	char *tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);
	char *data = (char*)malloc(sizeof(char) * BUFF_LEN);
	unsigned int id = 0;
	
	printf("Enter table name: ");
	scanf("%s", tab_name);
	printf("Enter data: ");
	scanf("%s", data);
	printf("Enter id (0 for new record): ");
	scanf("%u", &id);

	unsigned int i = 0;
	while (strcmp(db->tabs[i].name, tab_name) != 0) i++;

	if (id == 0)
		db->last_id++;
	add_cell(db, id != 0 ? id : db->last_id, data, i);

	SMART_FREE(tab_name);
	SMART_FREE(data);
}

void add_record_to_db(t_db *db)
{
	db->last_id++;

	for (unsigned int i = 0; i < db->count; i++)
	{
		char *data = (char*)malloc(sizeof(char) * BUFF_LEN);

		printf("Enter data for [%s] table: ", db->tabs[i].name);
		scanf("%s", data);

		add_cell(db, db->last_id, data, i);
		SMART_FREE(data);
	}
	
}