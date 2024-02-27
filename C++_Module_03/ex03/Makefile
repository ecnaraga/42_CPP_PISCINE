# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 11:05:22 by garance           #+#    #+#              #
#    Updated: 2024/02/26 17:59:39 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	diamondtrap

SRCS_DIR		= 	srcs/

SRCS 			=	main.cpp \
					ClapTrap.cpp \
					ScavTrap.cpp \
					FragTrap.cpp \
					DiamondTrap.cpp

OBJS_DIR		=	objs/

OBJS_NAME		=	$(SRCS:.cpp=.o)

OBJS 			=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

DEPS			=	$(OBJS:.o=.d)

CXX				=	c++

CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -MMD -g3

#################################### RULES ####################################

all				: 	$(NAME)

$(OBJS_DIR)%.o 	: 	$(SRCS_DIR)%.cpp
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