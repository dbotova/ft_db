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
	char *user_input = (char*)malloc(sizeof(char) * BUFF_LEN);
	int flag = 0;

	while (42)
	{
		system("clear");
		printf("\n");

		printf("%-30s", "[SEARCH DATA IN CELL(1)]");
		printf("%-25s", "[SEARCH COLUMN(2)]");
		printf("%-20s", "[BACK (3)]");
		printf("%-20s\n", "[EXIT (4)]");
		printf("\n\n");
		(!flag) ? printf(PROMPT1) : printf(PROMPT2);
		flag = 0;
		read_input(&user_input);
		//scanf("%s", user_input);
		if (!strcmp(user_input, "1"))
			search_record(db);
		else if (!strcmp(user_input, "2"))
			search_tab(db);
		else if (!strcmp(user_input, "3"))
			return;
		else if (!strcmp(user_input, "4"))
		{
			if (db)
				db = NULL;
			SMART_FREE(user_input);
			exit (0);
		}
		else
			flag = 1;
	}
	SMART_FREE(user_input);
}

static int 	checkMenuEntry(t_db *db, char *db_name)
{
	char *user_input = (char*)malloc(sizeof(char) * BUFF_LEN);
	
	if (read_input(&user_input) == -1)
	{
		SMART_FREE(user_input);
		return (-1);
	}

	if (!strcmp(user_input, "1"))
		create_tab(db);
	else if (!strcmp(user_input, "2"))
		add_record_to_tab(db);
	else if (!strcmp(user_input, "3"))
		delete_tab(db);
	else if (!strcmp(user_input, "4"))
		add_record_to_db(db);
	else if (!strcmp(user_input, "5"))
		print_search_menu(db);
	else if (!strcmp(user_input, "6"))
		serialize_db(db, db_name);
	else if (!strcmp(user_input, "7"))
		return (-1);
	else if (!strcmp(user_input, "8"))
	{
		if (db)
			db = NULL;
		exit (0);
	}
	else if (!strcmp(user_input, "9"))
	{
		printf("HAVE YOU CHECK ALL OUR AWESOME FEATURES (y/n)?\n");
		scanf("%s", user_input);
		if (!strcmp(user_input, "y"))
			system("open https://youtu.be/5AtkWnBjGBU?t=88");
	}
	else
	{
		SMART_FREE(user_input);
		return 1;
	}
	SMART_FREE(user_input);
	return (0);
}

void print_dbmenu(t_db *db, char *db_name)
{
	int flag;

	flag = 0;
	(!db) ? db = init_db() : 0;
	while (42)
	{
		system("clear");
		printf("\n");
		print_tabs(db);
		printf("\n\n");
		printf("%-20s", "[ADD COLUMN(1)]");
		printf("%-30s", "[ADD DATA TO CELL(2)]");
		printf("%-20s", "[DELETE(3)]");
		printf("%-20s\n", "[ADD ROW(4)]");
		printf("%-20s", "[SEARCH(5)]");
		printf("%-30s", "[EXPORT TO FILE (6)]");
		printf("%-20s", "[BACK (7)]");
		printf("%-20s\n", "[EXIT (8)]");
		printf("\n%s\n", "[LIKE (9)]");
		printf("\n\n");
		(!flag) ? printf(PROMPT1) : printf(PROMPT2); 
		flag = checkMenuEntry(db, db_name);
		if (flag == -1)
			return ;
	}
}

void print_mmenu(void)
{
	printf("\n\n");
	printf("%-25s", "[CREATE NEW DB (1)]");
	printf("%-32s", "[OPEN FROM FILE (2)]");
	printf("%s\n", "[EXIT (3)]");
	printf("\n\n");
	// (!flag) ? printf(PROMPT1) : printf(PROMPT2);
}
