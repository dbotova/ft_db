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

int main (void)
{
	char *user_input = (char*)malloc(sizeof(char) * BUFF_LEN);
	int flag = 0;
	t_db *db = NULL;

	while (42)
	{
		system("clear");
		print_mmenu();
		(!flag) ? printf(PROMPT1) : printf(PROMPT2);
		flag = 0;
		read_input(&user_input);
		if (!strcmp(user_input, "1"))
			create_newdb(db);
		else if (!strcmp(user_input, "2"))
			open_db(db);
		else if (!strcmp(user_input, "3"))
			break ;
		else 
			flag = 1;
	}
	SMART_FREE(user_input);
	return (0);
}
