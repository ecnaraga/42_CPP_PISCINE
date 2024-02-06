# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 15:55:56 by galambey          #+#    #+#              #
#    Updated: 2024/02/05 17:02:45 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	sed

SRCS_DIR	=	srcs/

SRCS		=	main.cpp

OBJS_DIR	=	./objs/

OBJS_NAMES	=	$(SRCS:.cpp=.o)

OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_NAMES))

DEPS		=	$(OBJS:.o=.d)

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -g3 -MMD

#################################### RULE #####################################

all				:	$(NAME)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.cpp
					mkdir -p $(@D)
					$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)			:	$(OBJS)
					$(CXX) $(CXXFLAGS) $< -o $@

-include $(DEPS)

clean			:
					rm -rf $(OBJS)

fclean			:	clean
					rm -f $(NAME)

re 				:	fclean
					make -j all

.PHONY			:	all clean fclean re