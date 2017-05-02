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

void open_db(t_db *db)
{
	char *db_name = (char *)malloc(sizeof(char) * BUFF_LEN);
	printf("Enter a name: ");
	scanf("%s", db_name);
	db = deserialize_db(db, db_name);

	if(!db)
		printf("FAIL\n");

	print_dbmenu(db, db_name);
	
	SMART_FREE(db_name);
}

void create_newdb(t_db *db)
{
	char *db_name = (char *)malloc(sizeof(char) * BUFF_LEN);
	//int user_input = 0;

	printf("Enter a name for your database: ");
	scanf("%s", db_name);
	print_dbmenu(db, db_name);
	
	SMART_FREE(db_name);
}

int main (void)
{
	int user_input = 0;
	t_db *db = NULL;

	system("clear");
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
	// if (db)
	// 	SMART_FREE(db);
	return (0);
}
