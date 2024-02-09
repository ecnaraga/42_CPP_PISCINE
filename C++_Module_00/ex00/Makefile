# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 11:44:02 by galambey          #+#    #+#              #
#    Updated: 2024/02/06 09:57:18 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	./megaphone

SRC_DIR		= 	src/

SRC			=	megaphone.cpp

OBJ_DIR		= 	.obj/

OBJ_NAME	=	$(SRC:.cpp=.o)

OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_NAME))

CXX			=	c++

CXX_FLAGS	=	-Wall -Wextra -Werror -std=c++98

#################################### RULES ####################################

all : 				$(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.cpp
					mkdir -p $(@D)
					$(CXX) $(CXX_FLAGS) -c $< -o $@
		
$(NAME) :		 	$(OBJ)
					$(CXX) $(CXX_FLAGS) $(OBJ) -o $@

clean :
					rm -rf $(OBJ_DIR)

fclean :		 	clean
					rm -f $(NAME)

re :		 		fclean
					make -j all

.PHONY :		 	all clean fclean re