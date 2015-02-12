# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/03 14:24:20 by rbenjami          #+#    #+#              #
#    Updated: 2015/02/12 17:58:23 by rbenjami         ###   ########.fr        #
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
					ft_cat.s		\
					\
					ft_memcmp.s		\

OBJS			=	$(SRCS:.s=.o)


all:			$(NAME)

$(NAME):		$(OBJS)
	@ar -rc $(NAME).a $(OBJS)
	@ranlib $(NAME).a
	@printf '\n\033[33mCompilation of %s: \033[32mSuccess \t	\
\033[34m[\033[32m✔\033[34m]\033[0m\n' $(NAME)

%.o:			%.s
	@echo -n .
	@nasm -f macho64 -o $@ $<

clean:
	@echo "\033[31m"Objects of libft.a : deleted"\033[0m"
	@rm -rf $(OBJS)

fclean:			clean
	@echo "\033[31m"libft.a : deleted"\033[0m"
	@rm -rf $(NAME).a

re:				fclean all

test: re
	@gcc -Wl,-no_pie -I. -L. -lfts main.c
	@./a.out

cat: re
	@gcc -Wl,-no_pie -I. -L. -lfts main_cat.c -o ft_cat

.PHONY: all, clean, fclean, re
