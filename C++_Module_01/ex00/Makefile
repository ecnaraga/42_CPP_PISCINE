# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 13:25:58 by galambey          #+#    #+#              #
#    Updated: 2024/01/31 13:32:25 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

SRC = main.cpp \
	  Zombe.cpp \
	  newZombie.cpp \
	  randomChump.cpp

OBJ = $(SRC:.cpp = .o)

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

%.o : %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) $< -o $@

clean :
	rm - f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re