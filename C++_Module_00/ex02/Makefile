# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garance <garance@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 11:39:35 by garance           #+#    #+#              #
#    Updated: 2024/01/27 11:48:00 by garance          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

SRC = Account.cpp \
	  tests.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

%.o : %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY: all clean fclean re