# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 11:39:35 by garance           #+#    #+#              #
#    Updated: 2024/02/06 10:11:20 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	account

SRCS_DIR	= 	srcs/

SRCS 		= 	Account.cpp \
	  			tests.cpp

OBJS_DIR	= 	.objs/

OBJS_NAMES	= 	$(SRCS:.cpp=.o)

OBJS		= 	$(addprefix $(OBJS_DIR), $(OBJS_NAMES))

CXX 			= 	c++

CXX_FLAGS 	= 	-Wall -Wextra -Werror -std=c++98

#################################### RULES ####################################

all 			: 	$(NAME)

$(OBJS_DIR)%.o 	: 	$(SRCS_DIR)%.cpp
					mkdir -p $(@D)
					$(CXX) $(CXX_FLAGS) -c $< -o $@

$(NAME) 		:	$(OBJS)
					$(CXX) $(CXX_FLAGS) $(OBJS) -o $@

clean 			:
					rm -rf $(OBJS_DIR)

fclean 			: 	clean
					rm -f $(NAME)

re 				: 	fclean
					make all

.PHONY			: 	all clean fclean re