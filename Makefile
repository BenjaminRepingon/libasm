# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/03 14:24:20 by rbenjami          #+#    #+#              #
#    Updated: 2015/02/05 14:13:18 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra

NAME			=	libfts

SRCS			=	return.s		\
					ft_bzero.s		\
					ft_strcat.s		\
					ft_isalpha.s	\
					ft_isdigit.s	\
					ft_isalnum.s	\
					ft_isascii.s	\
					ft_isprint.s	\
					ft_toupper.s	\
					ft_tolower.s	\
					ft_puts.s		\
					ft_strlen.s		\
					ft_memset.s		\
					ft_memcpy.s		\
					ft_strdup.s		\

OBJS			=	$(SRCS:.s=.o)


all:			$(NAME)

$(NAME):		$(OBJS)
	gcc main.c $(OBJS) -o $(NAME)

%.o:			%.s
	nasm -f macho64  -o $@ $<

clean:
	rm -rf $(OBJS)

fclean:			clean
	rm -rf $(NAME)

re:				fclean all


.PHONY: all, clean, fclean, re
