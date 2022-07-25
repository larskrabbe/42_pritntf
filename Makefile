# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 12:47:46 by lkrabbe           #+#    #+#              #
#    Updated: 2022/07/05 18:34:16 by lkrabbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PCFILES =	ft_printf.c\
			create_output.c\
			printf_convert.c\
			typesettera.c\
			typesetterb.c\
			fill_struct.c\
			calc_length.c

LIBFTCFILES =libft/ft_bzero.c\
			 libft/ft_calloc.c\
			 libft/ft_isdigit.c\
			 libft/ft_strlen.c\
			 libft/ft_strlen.c\
			 libft/ft_strchr.c\
			 libft/ft_strdup.c\
			 libft/ft_atoi.c


POFILES = $(PCFILES:.c=.o)

LIBFTOFILES= $(LIBFTCFILES:.c=.o)

HEADER = libftprintf.h

CC = cc

CFLAGS = -Wall -Werror -Wextra 

all: printf

bonus: fclean all

printf: $(POFILES) $(LIBFTOFILES) ft_printf.h libft/libft.h
	@ar -rs $(NAME) $(POFILES) $(LIBFTOFILES)

%.o: %.c
	@${CC} $(CFLAGS) -c $< -o $@

clean:
	@rm -f *.o
	@rm -f libft/*.o

fclean:clean
	@rm -f *.a
	
re: fclean all
	
.PHONY: clean  all printf fclean re 