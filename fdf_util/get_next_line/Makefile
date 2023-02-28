# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 05:07:53 by yel-hadr          #+#    #+#              #
#    Updated: 2023/02/28 21:38:57 by yel-hadr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libget_next_line.a
DEPS = get_next_line.h
CC = cc
FLAG = -Wall -Wextra -Werror
SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $^

clean :
	rm -f *.o

fclean :
	rm -rf *.o *.a

re : fclean all