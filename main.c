/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 19:30:37 by dbotova           #+#    #+#             */
/*   Updated: 2017/04/24 19:30:39 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void print_dbmenu(void)
{
	printf("[1] Create new record\n");
	printf("[2] View records\n");
	printf("[3] Search records\n");
	printf("[4] Export database\n");
	printf("[5] Back to Main Menu\n");
	printf("[6] Exit\n\n");
	printf(PROMPT);
}

void print_mmenu(void)
{
	printf("[1] Create new database\n");
	printf("[2] Open database\n");
	printf("[3] Exit\n\n");
	printf(PROMPT);
}

void open_db(t_db *db)
{
	if (!db)
		db = new_node();

	char *db_name = (char *)malloc(sizeof(char) * BUFF_LEN);
	printf("Enter a name: ");
	scanf("%s", db_name);
	deserialize_db(db, db_name);

	int user_input = 0;
	while (42)
	{
		print_dbmenu();
		scanf("%d", &user_input);
		if (user_input == 1)
			db = create_record(db);
		if (user_input == 2)
			print_db(db);
		if (user_input == 3)
			NOT_DONE;
		if (user_input == 4)
			serialize_db(db, db_name);
		if (user_input == 5)
			return ;
		if (user_input == 6)
			exit (0);
	}
	SMART_FREE(db_name);
	free_db(&db);
}

void create_newdb(t_db *db)
{
	char *db_name = (char *)malloc(sizeof(char) * BUFF_LEN);
	int user_input = 0;

	printf("Enter a name for your database: ");
	scanf("%s", db_name);
	while (42)
	{
		print_dbmenu();
		scanf("%d", &user_input);
		if (user_input == 1)
			db = create_record(db);
		if (user_input == 2)
			print_db(db);
		if (user_input == 3)
			NOT_DONE;
		if (user_input == 4)
			serialize_db(db, db_name);
		if (user_input == 5)
			return ;
		if (user_input == 6)
			exit (0);
	}
	SMART_FREE(db_name);
}

int main (void)
{
	int user_input = 0;
	t_db *db = NULL;

	while (42)
	{
		print_mmenu();
		scanf("%d", &user_input);
		if (user_input == 1)
			create_newdb(db);
		if (user_input == 2)
			open_db(db);
		if (user_input == 3)
			return (0);
	}
	if (db)
		free_db(&db);
	return (0);
}
