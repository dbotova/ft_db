/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_record.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:46:09 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/04 17:46:10 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void search_record(t_db *db)
{
	char *term = (char*)malloc(sizeof(char) * BUFF_LEN);

	printf("Enter cell data: ");
	read_input(&term);

	unsigned int key = hash(term);
	long long index = -1;
	print_tab_header(db);
	for (unsigned int i = 0; i < DICTIONARY_SIZE; i++)
	{
		if (db->tabs[i].map[key].name[0] != 0 && strcmp(db->tabs[i].map[key].name, term) == 0)
		{
			index = db->tabs[i].map[key].index;
			print_record(db, index);
			if (strcmp(db->tabs[i].map[key + 1].name, term) == 0)
			{
				key++;
				i = 0;
			}
		}
	}
	printf("BACK [0] << \n");
	read_input(&term);
	SMART_FREE(term);
}
