# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garance <garance@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 09:38:17 by galambey          #+#    #+#              #
#    Updated: 2024/03/22 10:31:17 by garance          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	iter

SRCS_DIR			=	srcs/

SRCS				=	main.cpp

OBJS_DIR			=	.objs/

OBJS_NAME		=	$(SRCS:.cpp=.o)

OBJS				=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

DEPS				=	$(OBJS:.o=.d)

CXX				=	c++

CXXFLAGS		=	-Wall -Wextra -Werror -MMD -std=c++98 -g3

##################################### RULE #####################################

all				:	$(NAME)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.cpp
					mkdir -p $(@D)
					$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)			:	$(OBJS)
					$(CXX) $(CXXFLAGS) $(OBJS) -o $@

-include $(DEPS)
					
clean			:
					rm -rf $(OBJS_DIR)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean
					make all

.PHONY			:	all test clean fclean re