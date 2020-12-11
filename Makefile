# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/17 22:01:09 by marc              #+#    #+#              #
#    Updated: 2020/11/29 18:36:26 by mterkhoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS = 	ft_converters.c \
		ft_converters_utils.c \
		ft_getters.c \
		ft_printf.c \
		ft_printf_utils.c

SURPL_O = 	ft_converters.o \
			ft_converters_utils.o \
			ft_getters.o \
			ft_printf.o \
			ft_printf_utils.o

CC = gcc

FLAGS = -c

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
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
