/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_db.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:48:53 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/04 17:48:54 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void add_record_to_db(t_db *db)
{
	if (!db->filled)
		return ;
	db->last_id++;

	for (unsigned int i = 0; i < DICTIONARY_SIZE; i++)
	{
		if (db->tabs[i].name[0] != 0)
		{
			char *data = (char*)malloc(sizeof(char) * BUFF_LEN);
			
			printf("Enter data for [%s] table: ", db->tabs[i].name);
			read_input(&data);

			add_cell(db, db->last_id, data, i);
			SMART_FREE(data);
		}
	}
	
}
