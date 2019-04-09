#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcremin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 18:43:04 by jcremin           #+#    #+#              #
#    Updated: 2019/01/24 20:15:27 by jcremin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS = ./*.c

SRO = ./*.o

HEADER_DIRECT = ./

COMM = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
				gcc $(COMM) $(SRCS) -I$(HEADER_DIRECT)
				ar rc $(NAME) $(SRO)
				ranlib $(NAME)
clean:
				rm -f $(SRO)
fclean: clean 
				rm -f $(NAME)
re: fclean all
