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
# define TAB_HEADER printf("|%-9s|%-18s|%-9s|%-18s|\n", "ID", "NAME", "AGE", "SCHOOL");
# define DICTIONARY_SIZE 1000

typedef struct		s_db
{
	int id;
	char *name;
	char *age;
	char *school;
	size_t name_len;
	size_t age_len;
	size_t school_len;
	struct s_db *next;
	struct s_db *prev;
	struct s_db dictionary[DICTIONARY_SIZE];
}					t_db;

t_db *new_node(void);
void free_node(t_db *node);
void free_db(t_db **db);
void add_node(t_db **db, char *name, char *age, char *school);
void add_node_from_file(t_db **db, char *name, char *age, char *school, int id);
void serialize_db(t_db *db, char *filename);
t_db *deserialize_db(t_db *db, char *path);
t_db *create_record(t_db *db);
void print_db(t_db *db);
void print_dbmenu(t_db *db, char *db_name);
void print_mmenu(void);

void print_debugmenu(t_db *db);
unsigned int hash(t_db *db);

#endif
