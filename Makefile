# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/17 22:01:09 by marc              #+#    #+#              #
#    Updated: 2020/12/12 10:23:28 by mterkhoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_parser.c	\
		ft_parser_utils.c \
		ft_printf.c \
		ft_utils.c \
		ft_converters_chars.c \
		ft_converters_numbers.c \
		ft_converters_utils.c \
		ft_list.c

SURPL_O =	ft_parser.o \
			ft_parser_utils.o \
			ft_printf.o \
			ft_utils.o \
			ft_converters_chars.o \
			ft_converters_numbers.o \
			ft_converters_utils.o \
			ft_list.o

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

INCLUDES = -I.

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O)

fclean : clean
	rm -rf $(NAME) libft/libft.a

re : fclean all
