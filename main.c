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

int main ()
{	
	t_db *database;
	init_db(database, "Students");

	add_tab(database, "Name");
	add_cells(database, 0, 0, "Mark Smith");
	add_cells(database, 0, 1, "Art Sedov");

	printf("id: %d name: %s\n", database->tables[0].cells[0].id, database->tables[0].cells[0].data);
	printf("id: %d name: %s\n", database->tables[0].cells[1].id, database->tables[0].cells[1].data);

	add_tab(database, "Gender");
	add_cells(database, 1, 0, "Male");
	add_cells(database, 1, 1, "Male");

	add_tab(database, "Age");
	add_cells(database, 2, 0, "23");
	add_cells(database, 2, 1, "56");

	return (0);
}
