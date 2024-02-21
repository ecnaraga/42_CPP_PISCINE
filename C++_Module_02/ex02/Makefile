# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 15:41:57 by galambey          #+#    #+#              #
#    Updated: 2024/02/21 15:42:10 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	fixed

SRCS_DIR		=	srcs/

SRCS			=	main.cpp \
					Fixed.cpp

OBJS_DIR		=	objs/

OBJS_NAME		=	$(SRCS:.cpp=.o)

OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

DEPS			=	$(OBJS:.o=.d)

CXX				=	c++

CXXFLAGS		=	-Wall -Wextra -Werror -Weverything -MMD -std=c++98

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