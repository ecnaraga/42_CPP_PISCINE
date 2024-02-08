# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 10:52:39 by garance           #+#    #+#              #
#    Updated: 2024/02/08 15:43:44 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	brain

SRC_DIR		= 	src/

SRC			= 	main.cpp

OBJ_NAME	= 	$(SRC:.cpp=.o)

OBJ_DIR		=	.obj/

OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_NAME))

DEPS		=	$(OBJS:.o=.d)

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -g3 -MMD -std=c++98

#################################### RULE #####################################

all				:	$(NAME)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.cpp
					mkdir -p $(@D)
					$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)			:	$(OBJ)
					$(CXX) $(CXXFLAGS) $(OBJ) -o $@

-include $(DEPS)

clean			:
					rm -rf $(OBJ_DIR)

fclean			:	clean
					rm -f $(NAME)

re 				:	fclean
					make all

.PHONY			:	all clean fclean re 