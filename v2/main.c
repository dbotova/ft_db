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

	printf("Enter a name for your database: ");
	scanf("%s", db_name);
	print_dbmenu(db, db_name);
	
	SMART_FREE(db_name);
}

int main (void)
{
	char user_input[10];
	int flag = 0;
	t_db *db = NULL;

	while (42)
	{
		system("clear");
		print_mmenu(flag);
		scanf("%s", user_input);
		if (!strcmp(user_input, "1"))
			create_newdb(db);
		else if (!strcmp(user_input, "2"))
			open_db(db);
		else if (!strcmp(user_input, "3"))
			return (0);
		else 
			flag = 1;
	}
	return (0);
}
