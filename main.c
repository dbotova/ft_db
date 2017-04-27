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

void print_db(t_db *cur)
{
	int i = 1;
	while (cur)
	{
		printf("\nStudent #%d\n", i++);
		printf("Name: %s\n", cur->name);
		printf("Age: %s\n", cur->age);
		printf("School: %s\n", cur->school);
		cur = cur->next;
	}
}

int main ()
{
	t_db *db = (t_db*)malloc(sizeof(t_db));
	db->name = NULL;
	db->age = NULL;
	db->school = NULL;
	db->next = NULL;

	printf("\nREAD FROM FILE TO LIST\n");
	char *name = NULL;
	scanf("Enter path: %s\n", name);
	deserialize_db(db, name);
	print_db(db);

	t_db *cur = db;
	while (cur->next)
		cur = cur->next;
	cur->next = (t_db*)malloc(sizeof(t_db));
	cur = cur->next;
	cur->name_len = 11;
	cur->age_len = 2;
	cur->school_len = 4;
	cur->name = "Vasya Pupkin";
	cur->age = "20";
	cur->school = "none";

	printf("\nPRINT AFTER UPDATE\n");
	print_db(db);

	// //dump to file
	scanf("Enter path for dump: %s\n", name);
	serialize_db(db, name);
	
	//free_list(db);

	// read from file
	t_db *db_1 = (t_db*)malloc(sizeof(t_db));
	db_1->name = NULL;
	db_1->age = NULL;
	db_1->school = NULL;
	db_1->next = NULL;

	printf("\nREAD FROM FILE TO LIST AFTER UPDATE 2\n");
	deserialize_db(db_1, name);
	print_db(db_1);
	//free_list(db_1);

	return (0);
}
