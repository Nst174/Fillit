#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcremin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 18:43:04 by jcremin           #+#    #+#              #
#    Updated: 2019/04/06 21:33:24 by jcremin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS = ./libft/*.c

SRO = ./*.o

HEADER_DIRECT = ./libft/

COMM = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
				gcc $(COMM) $(SRCS) -I$(HEADER_DIRECT)
				ar rc $(NAME) $(SRO)
				ranlib $(NAME)
				gcc fill_open.c fill_format.c fill_solver.c fill_sort.c $(NAME)
clean:
				rm -f $(SRO)
fclean: clean 
				rm -f $(NAME)
				rm a.out
re: fclean all