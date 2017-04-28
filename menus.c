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

void print_dbmenu(t_db *db)
{
	//system("clear");

	printf("\n");
	print_db(db);

	printf("\n\n");
	printf("%-25s", "[Create new record (1)]");
	printf("%-25s", "[Search records (2)]");
	printf("%-25s", "[Export database (3)]");
	printf("%-25s", "[Back to Main Menu (4)]");
	printf("%-25s\n", "[Exit (5)]");
	printf("\n\n");
	printf(PROMPT);
}

void print_mmenu(void)
{
	printf("\n\n");
	printf("%-35s", "[Create new database (1)]");
	printf("%-30s", "[Open database (2)]");
	printf("%-30s\n", "[Exit (3)]");
	printf("\n\n");
	printf(PROMPT);
}
