# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 14:55:09 by galambey          #+#    #+#              #
#    Updated: 2024/01/26 17:42:10 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=./phonebook

SRC=PhoneBook.cpp\
	Contact.cpp\
	main.cpp

OBJ=$(SRC:.cpp=.o)

CC=c++

FLAGS=-Wall -Wextra -Werror -std=c++98

all : $(NAME)

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@
		
$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean
	make -j all

.PHONY : all clean fclean re