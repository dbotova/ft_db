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
# include <unistd.h>
# define SMART_FREE(x) {free(x); x = NULL;}
# define PROMPT "=^..^= : "
# define NOT_DONE {printf("UNDER IMPLEMENTATION\n"); sleep(2);}
# define BUFF_LEN 20
# define TAB_DELIMETR printf("-----------------------------------------------------------\n")
//# define TAB_HEADER printf("|%-9s|%-18s|%-9s|%-18s|\n", "ID", "NAME", "AGE", "SCHOOL");
# define DICTIONARY_SIZE 1000

typedef struct	s_cell
{
	int id;
	char data[BUFF_LEN];
}				t_cel;

typedef struct	s_tab
{
	char name[BUFF_LEN];
	unsigned int size;
	t_cell data[DICTIONARY_SIZE];
	struct s_tab *next;
	struct s_tab *prev;
}

typedef struct		s_db
{
	t_tab *tabs;
	int last_id;
}					t_db;

//t_db *new_node(void);
//void free_node(t_db *node);
//void free_db(t_db **db);
//void add_node(t_db **db, char *name, char *age, char *school);
//void add_node_from_file(t_db **db, char *name, char *age, char *school, int id);
//void serialize_db(t_db *db, char *filename);
//t_db *deserialize_db(t_db *db, char *path);
//t_db *create_record(t_db *db);
void print_tabs(t_db *db);
void print_dbmenu(t_db *db, char *db_name);
void print_mmenu(void);

void print_debugmenu(t_db *db);
unsigned int hash(t_db *db);

#endif
