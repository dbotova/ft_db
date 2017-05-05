/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:46:52 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/04 17:46:53 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void search_tab(t_db *db)
{
	char *term = (char*)malloc(sizeof(char) * BUFF_LEN);
	unsigned int key = 0;

	printf("Enter column name: (0 to cancel) ");
	while (42)
	{
		read_input(&term);

		key = hash(term);

		if (strcmp(db->map[key].name, term))
				printf("Invalid column name, please try again...\n"); 
		else if (!strcmp(term, "0"))
			break;
		else
			break;
	}
	print_tab(db, db->map[key].index);

	printf("BACK [0] << \n");
	int tmp = -1;
	scanf("%d", &tmp);
	SMART_FREE(term);
}
