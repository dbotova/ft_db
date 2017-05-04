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


static void print_tab_header(t_db *db)
{
	for (unsigned int i = 0; i <= db->filled; i++)
		printf("--------------------");
	printf("-\n");
	printf("|%-19s", "ID");
	for (unsigned int i = 0; i < DICTIONARY_SIZE; i++)
	{
		if (db->tabs[i].name[0] != 0)
			printf("|%-19s", db->tabs[i].name);
	}
	printf("|\n");
	for (unsigned int i = 0; i <= db->filled; i++)
		printf("--------------------");
	printf("-\n");
}

void print_tabs(t_db *db)
{	
	if (db->filled == 0)
	{
		TAB_DELIMETR;
		printf("|%35s%-22s|\n", "***EMPTY***", "");
		TAB_DELIMETR;
		return ;
	}
	print_tab_header(db);
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
	for (unsigned int i = 0; i <= db->filled; i++)
		printf("--------------------");
	printf("-\n");
}

void add_record_to_tab(t_db *db)
{
	char *tab_name = (char*)malloc(sizeof(char) * BUFF_LEN);
	char *data = (char*)malloc(sizeof(char) * BUFF_LEN);
	unsigned int id = 0;
	unsigned int i;
	int flag = 0;

	printf("Enter table name: ");
	while (1)
	{
		i = 0;
		scanf("%s", tab_name);
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
	printf("Enter data: ");
	scanf("%s", data);
	printf("Enter id (0 for new record): ");
	scanf("%u", &id);
	
	if (id == 0)
		db->last_id++;
	add_cell(db, id != 0 ? id : db->last_id, data, i);

	SMART_FREE(tab_name);
	SMART_FREE(data);
}

void add_record_to_db(t_db *db)
{
	db->last_id++;

	for (unsigned int i = 0; i < DICTIONARY_SIZE; i++)
	{
		if (db->tabs[i].name[0] != 0)
		{
			char *data = (char*)malloc(sizeof(char) * BUFF_LEN);
			
			printf("Enter data for [%s] table: ", db->tabs[i].name);
			scanf("%s", data);

			add_cell(db, db->last_id, data, i);
			SMART_FREE(data);
		}
	}
	
}

void print_record(t_db *db, long long index)
{
	if (index < 0)
		return ;
	
	printf("|%-20lld", index + 1);
	for (unsigned int i = 0; i < DICTIONARY_SIZE; i++)
	{
		if (db->tabs[i].name[0] != 0)
			printf("|%-19s", db->tabs[i].data[index].data);
	}
	printf("|\n");
	for (unsigned int i = 0; i <= db->filled; i++)
		printf("--------------------");
	printf("-\n");

}

void print_tab(t_db *db, long long index)
{
	if (index < 0)
		return ;
	printf("----------------------------------------\n");
	printf("|%-20s", "ID");
	printf("|%-20s\n", db->tabs[index].name);
	printf("----------------------------------------\n");
	for (unsigned int i = 0; i < db->last_id; i++)
			printf("|%-20d|%-20s|\n", i + 1, db->tabs[index].data[i].data);
	printf("----------------------------------------\n");
}

void search_tab(t_db *db)
{
	char *term = (char*)malloc(sizeof(char) * BUFF_LEN);

	printf("Enter search term: ");
	scanf("%s", term);

	unsigned int key = hash(term);
	print_tab(db, db->map[key].index);

	printf("BACK [0] << \n");
	int tmp = -1;
	scanf("%d", &tmp);
	SMART_FREE(term);
}

void search_record(t_db *db)
{
	char *term = (char*)malloc(sizeof(char) * BUFF_LEN);

	printf("Enter search term: ");
	scanf("%s", term);

	unsigned int key = hash(term);
	long long index = -1;
	print_tab_header(db);
	for (unsigned int i = 0; i < DICTIONARY_SIZE; i++)
	{
		if (db->tabs[i].map[key].name[0] != 0 && strcmp(db->tabs[i].map[key].name, term) == 0)
		{
			index = db->tabs[i].map[key].index;
			print_record(db, index);
			if (strcmp(db->tabs[i].map[key + 1].name, term) == 0)
			{
				key++;
				i = 0;
			}
		}
	}
	printf("BACK [0] << \n");
	int tmp = -1;
	scanf("%d", &tmp);
	SMART_FREE(term);
}
