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

// void 	termsAndConditions(char *user_input)
// {
// 	printf("		YOU AGREE WITH FOLLOWING TERMS AND CONDITIONS\n \
// 	 	THAT ALL THE DATA YOU ENTER TO OUR DATABASE WILL \n \
// 	 	NOT INLCUDE THE	FOLLWING CHARACTERS:\n \
// 		- SPACE;\n \
// 		- NEW LINE;\n \
// 		- TAB LINE;\n\n \
// 		[ENTER (1) FOR YES]\n \
// 		[PRESS ANY KEY TO EXIT]\n");
// 	read_input(&user_input);
// 	if(strcmp(user_input, "1"))
// 		exit(1);
// }

int main (void)
{
	char *user_input = (char*)malloc(sizeof(char) * BUFF_LEN);
	int flag = 0;
	t_db *db = NULL;

	// termsAndConditions(user_input);
	while (42)
	{
		system("clear");
		print_mmenu(flag);
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
