# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 09:38:17 by galambey          #+#    #+#              #
#    Updated: 2024/03/05 13:48:42 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	bureaucrat

SRC_DIR			=	src/

SRC				=	main.cpp \
					Bureaucrat.cpp

OBJ_DIR			=	.obj/

OBJ_NAME		=	$(SRC:.cpp=.o)

OBJ				=	$(addprefix $(OBJ_DIR), $(OBJ_NAME))

DEP				=	$(OBJ:.o=.d)

CXX				=	c++

CXXFLAGS		=	-Wall -Wextra -Werror -MMD -std=c++98 -g3

##################################### RULE #####################################

all				:	$(NAME)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.cpp
					mkdir -p $(@D)
					$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)			:	$(OBJ)
					$(CXX) $(CXXFLAGS) $(OBJ) -o $@

-include $(DEP)

clean			:
					rm -rf $(OBJ_DIR)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean
					make all

.PHONY			:	all clean fclean re