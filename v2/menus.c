/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:13:00 by dbotova           #+#    #+#             */
/*   Updated: 2017/04/27 18:13:01 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void print_debugmenu(t_db *db)
{
	int user_input = 0;

	while (42)
	{
		printf("\n");
		print_tabs(db);

		printf("\n\n");
		printf("%-13s", "[HASH (1)]");
		printf("%-15s", "[DB STRUCT (2)]");
		printf("%-15s", "[SHOW TABS (3)]");
		printf("%-12s", "[BACK (4)]");
		printf("%-13s\n", "[EXIT (5)]");
		printf("\n\n");
		printf(PROMPT);

		scanf("%d", &user_input);
		if (user_input == 1)
		{
			char *tmp = (char*)malloc(sizeof(char) * BUFF_LEN);
			scanf("%s", tmp);
			printf("%u\n", hash(tmp));
		}
		if (user_input == 2)
		{
			printf("count: %u\n", db->count);
			printf("last_id: %u\n", db->last_id);
		}
		if (user_input == 3)
		{
			printf("count: %u\n", db->count);
			printf("last_id: %u\n", db->last_id);

			for (unsigned int i = 0; i < db->count; i++)
			{
				printf("TAB: %s\n", db->tabs[i].name);
				for (unsigned int j = 0; db->tabs[i].data[j].data[0] != 0; j++)
					printf("id: %u data: %s\n", db->tabs[i].data[j].id, db->tabs[i].data[j].data);
			}

			printf("\n");
		}
		if (user_input == 4)
			return ;
		if (user_input == 5)
		{
			//SMART_FREE(db);
			exit (0);
		}
	}
}

void print_dbmenu(t_db *db, char *db_name)
{
	int user_input = 0;
	if (!db)
		db = init_db();

	while (42)
	{
		system("clear");
		printf("\n");
		print_tabs(db);

		printf("\n\n");
		printf("%-20s", "[ADD TAB(1)]");
		printf("%-20s", "[ADD TO TABLE(2)]");
		printf("%-20s", "[DELETE TAB(3)]");
		printf("%-20s\n", "[ADD RECORD(4)]");
		printf("%-20s", "[SEARCH (5)]");
		printf("%-20s", "[EXPORT (6)]");
		printf("%-20s", "[BACK (7)]");
		printf("%-20s\n", "[EXIT (8)]");
		printf("\n%s\n", "[DEBUG (0)]");
		printf("\n\n");
		printf(PROMPT);

		scanf("%d", &user_input);
		if (user_input == 1)
			create_tab(db);
		if (user_input == 2)
			delete_tab(db);
		if (user_input == 3)
			add_record_to_tab(db);
		if (user_input == 4)
			add_record_to_db(db);
		if (user_input == 5)
			NOT_DONE;
		if (user_input == 6)
			serialize_db(db, db_name);
		if (user_input == 7)
			return ;
		if (user_input == 8)
		{
			//SMART_FREE(db);
			exit (0);
		}
		if (user_input == 0)
		{
			system("clear");
			print_debugmenu(db);
		}
	}
}

void print_mmenu(void)
{
	printf("\n\n");
	printf("%-15s", "[CREATE (1)]");
	printf("%-12s", "[OPEN (2)]");
	printf("%s\n", "[EXIT (3)]");
	printf("\n\n");
	printf(PROMPT);
}
