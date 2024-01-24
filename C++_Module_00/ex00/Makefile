# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 11:44:02 by galambey          #+#    #+#              #
#    Updated: 2024/01/24 14:03:47 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=./megaphone

SRC=megaphone.cpp

OBJ=$(SRC:.cpp=.o)

CC=c++

FLAGS=-Wall -Wextra -Werror -std=c++98

all : $(NAME)

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@
		
$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

clean :
	rm -f megaphone.o

fclean : clean
	rm -f $(NAME)

re : fclean
	make -j all

.PHONY : all clean fclean re