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
# include <sys/stat.h>
# define SMART_FREE(x) {free(x); x = NULL;}

typedef struct		s_db
{
	char *name;
	char *age;
	char *school;
	int name_len;
	int age_len;
	int school_len;
	struct s_db *next;
	struct s_db *prev;
}					t_db;

t_db *new_node(t_db *node);
void free_node(t_db *node);
void serialize_db(t_db *db, char *filename);
void deserialize_db(t_db *db, char *path);

#endif
