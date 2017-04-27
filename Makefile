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
			dllist.o \
			records.o

HEADERS =	ft_db.h

CFLAGS += 	-Wall -Werror -Wextra

NAME =		cooldb

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ): $(HEADERS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all