# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garance <garance@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 13:25:58 by galambey          #+#    #+#              #
#    Updated: 2024/02/03 10:45:36 by garance          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 	zombie

SRCS_DIR		=	srcs/
	  				
SRCS 			= 	randomChump.cpp \
					main.cpp \
	  				Zombie.cpp \
	  				newZombie.cpp \

OBJS_DIR		=	.objs/

OBJS_NAME		= 	$(SRCS:.cpp=.o)

OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

CC 				= 	c++

CPP_FLAGS 		= 	-Wall -Wextra -Werror -std=c++98 -g3

#################################### RULE #####################################

all 			: 	$(NAME)

$(OBJS_DIR)%.o 	: 	$(SRCS_DIR)%.cpp
					mkdir -p $(@D)
					$(CC) $(CPP_FLAGS) -c $< -o $@

$(NAME) 		: 	$(OBJS)
					$(CC) $(CPP_FLAGS) $(OBJS) -o $@

clean 			:
					rm -rf $(OBJS_DIR)

fclean 			: 	clean
					rm -f $(NAME)

re 				: 	fclean
					make all

.PHONY 			: 	all clean fclean re