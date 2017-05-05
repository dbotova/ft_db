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

void print_tab_header(t_db *db)
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

