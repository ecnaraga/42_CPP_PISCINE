# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 09:38:17 by galambey          #+#    #+#              #
#    Updated: 2024/03/05 15:27:11 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	bureaucrat

SRCS_DIR		=	srcs/

SRCS			=	main.cpp \
					Bureaucrat.cpp \
					Form.cpp

OBJS_DIR		=	.objs/

OBJS_NAME		=	$(SRCS:.cpp=.o)

OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

DEPS			=	$(OBJS:.o=.d)

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

.PHONY			:	all clean fclean re