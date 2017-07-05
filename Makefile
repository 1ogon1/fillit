# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/19 17:03:05 by rkonoval          #+#    #+#              #
#    Updated: 2017/02/15 15:01:59 by rkonoval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJECTS = fillit.o\
		  push_back.o\
		  ft_putchar.o\
		  ft_putstr.o\
		  cheacker.o\
		  create_list.o\
		  ft_error.o\
		  ft_strlen.o\
		  create_map.o\
		  print_map.o\
		  algorithm.o

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

fillit.o : fillit.c
	$(CC) $(CFLAGS) -c fillit.c

push_back.o : push_back.c
	$(CC) $(CFLAGS) -c push_back.c

ft_putchar.o : ft_putchar.c
	$(CC) $(CFLAGS) -c ft_putchar.c

ft_putstr.o : ft_putstr.c
	$(CC) $(CFLAGS) -c ft_putstr.c

cheacker.o : cheacker.c
	$(CC) $(CFLAGS) -c cheacker.c

create_list.o : create_list.c
	$(CC) $(CFLAGS) -c create_list.c

ft_error.o : ft_error.c
	$(CC) $(CFLAGS) -c ft_error.c

ft_strlen.o : ft_strlen.c
	$(CC) $(CFLAGS) -c ft_strlen.c

create_map : create_map.c
	$(CC) $(CFLAGS) -c create_map.c

print_map : print_map.c
	$(CC) $(CFLAGS) -c print_map.c

algorithm : algorithm.c
	$(CC) $(CFLAGS) -c algorithm.c
