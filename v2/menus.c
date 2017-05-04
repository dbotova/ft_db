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


void print_search_menu(t_db *db)
{
	char user_input[BUFF_LEN] = {0};
	int flag = 0;

	while (42)
	{
		system("clear");
		printf("\n");

		printf("%-20s", "[SEARCH RECORD(1)]");
		printf("%-20s", "[SEARCH TABLE(2)]");
		printf("%-20s", "[BACK (3)]");
		printf("%-20s\n", "[EXIT (4)]");
		printf("\n\n");
		(!flag) ? printf(PROMPT1) : printf(PROMPT2);

		scanf("%s", user_input);
		if (!strcmp(user_input, "1"))
		{
			search_record(db);
			flag = 0;
		}
		if (!strcmp(user_input, "2"))
		{
			search_tab(db);
			flag = 0;
		}
		if (!strcmp(user_input, "3"))
			return ;
		if (!strcmp(user_input, "4"))
		{
			flag = 0;
			if (db)
				db = NULL;
			exit (0);
		}
	}
}

void print_dbmenu(t_db *db, char *db_name)
{
	char user_input[BUFF_LEN] = {0};
	int flag = 0;
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
		printf("%-20s\n", "[DELETE RECORD (33)]");
		printf("%-20s\n", "[ADD RECORD(4)]");
		printf("%-20s", "[SEARCH(5)]");
		printf("%-20s", "[EXPORT (6)]");
		printf("%-20s", "[BACK (7)]");
		printf("%-20s\n", "[EXIT (8)]");
		printf("\n%s\n", "[LIKE (9)]");
		printf("\n\n");
		(!flag) ? printf(PROMPT1) : printf(PROMPT2); 

		scanf("%s", user_input);
		if (!strcmp(user_input, "1"))
		{
			create_tab(db);
			flag = 0;
		}
		else if (!strcmp(user_input, "2"))
		{
			add_record_to_tab(db);
			flag = 0;
		}
		else if (!strcmp(user_input, "3"))
		{
			delete_tab(db);
			flag = 0;
		}
		else if (!strcmp(user_input, "33"))
		{
			int id = 0;
			printf("Enter id: ");
			scanf("%d", &id);
			deleteID(db, id);
			flag = 0;
		}
		else if (!strcmp(user_input, "4"))
		{
			add_record_to_db(db);
			flag = 0;
		}
		else if (!strcmp(user_input, "5"))
		{
			print_search_menu(db);
			flag = 0;
		}
		else if (!strcmp(user_input, "6"))
		{
			serialize_db(db, db_name);
			flag = 0;
		}
		else if (!strcmp(user_input, "7"))
		{
			return;
			flag = 0;
		}
		else if (!strcmp(user_input, "8"))
		{
			if (db)
				db = NULL;
			flag = 0;
			exit (0);
		}
		else if (!strcmp(user_input, "9"))
		{
			printf("HAVE YOU CHECK ALL OUR AWESOME FEATURES (y/n)?\n");
			scanf("%s", user_input);
			if (!strcmp(user_input, "y"))
			{
				system("open https://youtu.be/5AtkWnBjGBU?t=88");
				flag = 0;
			}
		}
		else 
			flag = 1;
	}
}

void print_mmenu(int flag)
{
	printf("\n\n");
	printf("%-15s", "[CREATE (1)]");
	printf("%-12s", "[OPEN (2)]");
	printf("%s\n", "[EXIT (3)]");
	printf("\n\n");
	(!flag) ? printf(PROMPT1) : printf(PROMPT2);
}
