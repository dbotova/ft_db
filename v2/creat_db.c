/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_db.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:41:21 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/04 17:41:23 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void create_newdb(t_db *db)
{
	char *db_name = (char *)malloc(sizeof(char) * BUFF_LEN);

	printf("Enter a name for your database: ");
	scanf("%s", db_name);
	print_dbmenu(db, db_name);
	
	SMART_FREE(db_name);
}
