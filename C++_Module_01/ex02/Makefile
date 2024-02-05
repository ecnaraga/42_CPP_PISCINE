# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garance <garance@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 10:52:39 by garance           #+#    #+#              #
#    Updated: 2024/02/04 11:43:00 by garance          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	brain

SRC_DIR		= 	src/

SRC			= 	main.cpp

OBJ_NAME	= 	$(SRC:.cpp=.o)

OBJ_DIR		=	.obj/

OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_NAME))

DEPS		=	$(OBJS:.o=.d)

CC			=	c++

CPP_FLAGS	=	-Wall -Wextra -Werror -g3 -MMD -std=c++98

#################################### RULE #####################################

all				:	$(NAME)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.cpp
					mkdir -p $(@D)
					$(CC) $(CPP_FLAGS) -c $< -o $@

$(NAME)			:	$(OBJ)
					$(CC) $(CPP_FLAGS) $(OBJ) -o $@

-include $(DEPS)

clean			:
					rm -rf $(OBJ_DIR)

fclean			:	clean
					rm -f $(NAME)

re 				:	fclean
					make all

.PHONY			:	all clean fclean re 