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
	if (!db)
	{
		printf("|%35s%-22s|\n", "***EMPTY***", "");
		TAB_DELIMETR;
		return ;
	}
	t_tab *cur = db->tabs;

	while (cur)
	{
		printf("|%-20d", cur->name);
		cur = cur->next;
	}
	printf("|\n");
	TAB_DELIMETR;
}

// t_db *create_record(t_db *db)
// {
// 	char *name = (char*)malloc(sizeof(char) * BUFF_LEN);
// 	char *age = (char*)malloc(sizeof(char) * BUFF_LEN);
// 	char *school = (char*)malloc(sizeof(char) * BUFF_LEN);

// 	printf("Enter new name: ");
// 	scanf("%s", name);
// 	printf("Enter age: ");
// 	scanf("%s", age);
// 	printf("Enter school: ");
// 	scanf("%s", school);

// 	add_node(&db, name, age, school);

// 	SMART_FREE(name);
// 	SMART_FREE(age);
// 	SMART_FREE(school);

// 	return (db);
// }
