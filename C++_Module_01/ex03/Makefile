# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 11:36:51 by garance           #+#    #+#              #
#    Updated: 2024/02/08 15:44:43 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	war

SRCS_DIR	= 	srcs/

SRCS 		=	main.cpp \
				Weapon.cpp \
				HumanA.cpp \
				HumanB.cpp

OBJS_NAMES	=	$(SRCS:.cpp=.o)

OBJS_DIR	=	.objs/

OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_NAMES))

DEPS		=	$(OBJS:.o=.d)

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -g3 -MMD -std=c++98

#################################### RULE #####################################

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

re 				:	fclean
					make all

.PHONY			:	all clean fclean re