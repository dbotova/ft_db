# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbotova <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/24 21:28:31 by dbotova           #+#    #+#              #
#    Updated: 2017/04/24 21:28:32 by dbotova          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS =		main.o \
			deserialize.o \
			serialize.o \
			db.o \
			print_records.o \
			menus.o \
			hash.o \
			tabs.o \
			read_input.o \
			open_db.o \
			search_tab.o \
			search_record.o \
			creat_db.o \
			add_to_db.o \
			add_to_tab.o


HEADERS =	ft_db.h

CFLAGS += 	-Wall -Werror -Wextra

NAME =		ft_db

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ): $(HEADERS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all