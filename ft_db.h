/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:37:32 by dbotova           #+#    #+#             */
/*   Updated: 2017/04/24 18:37:36 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# define NAME_LEN 30
# define DATA_LEN 100
# define DEFAULT_TABLE_SIZE 1000

typedef struct		s_cell
{
	char			data[DATA_LEN];
	unsigned int	id;
}					t_cell;

typedef struct		s_table
{
	t_cell			cells[DEFAULT_TABLE_SIZE];
	char			name[NAME_LEN];
	unsigned int	last_id;
	unsigned int	size;
}					t_table;

typedef struct		s_db
{
	char			name[NAME_LEN];
	t_table			tables[DEFAULT_TABLE_SIZE];
	unsigned int	size;
}					t_db;

void	init_db(t_db *database, char *db_name);
void	add_tab(t_db *database, char *tab_name);
void	add_cells(t_db *database, int pos, int id, char *data);

#endif
