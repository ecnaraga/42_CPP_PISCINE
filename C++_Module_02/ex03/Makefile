# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 11:37:36 by galambey          #+#    #+#              #
#    Updated: 2024/02/23 16:49:42 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	bsp

SRCS_DIR		=	srcs/

SRCS			=	main.cpp \
					Fixed.cpp \
					Point.cpp \
					bsp.cpp

OBJS_DIR		=	objs/

OBJS_NAME		=	$(SRCS:.cpp=.o)

OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

DEPS			=	$(OBJS:.o=.d)

CXX				=	c++

CXXFLAGS		=	-Wall -Wextra -Werror -Weverything -MMD -g3 -std=c++98

#################################### RULE #####################################

all				:	$(NAME)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.cpp
					mkdir -p $(@D)
					$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)			:	$(OBJS)
					$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean			:
					rm -rf $(OBJS_DIR)

fclean			:	clean
					rm -f $(NAME)

re 				:	fclean
					make all

.PHONY			: all clean fclean re