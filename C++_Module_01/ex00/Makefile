# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 13:25:58 by galambey          #+#    #+#              #
#    Updated: 2024/02/02 17:19:30 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 	zombie

SRCS_DIR		=	srcs/
SRCS 			= 	main.cpp \
	  				Zombie.cpp \
	  				newZombie.cpp \
	  				randomChump.cpp

OBJS_DIR		=	.objs/

OBJS_NAME		= 	$(SRCS:.cpp=.o)

OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

CC 				= 	c++

CPP_FLAGS 		= 	-Wall -Wextra -Werror -std=c++98

#################################### RULE #####################################

all 			: 	$(NAME)

$(OBJS_DIR)%.o 	: 	$(SRCS_DIR)%.cpp
					mkdir -p $(@D)
					$(CC) $(CPP_FLAGS) -c $< -o $@

$(NAME) 		: 	$(OBJS)
					$(CC) $(CPP_FLAGS) $< -o $@

clean 			:
					rm - f $(OBJS)

fclean 			: 	clean
					rm -f $(NAME)

re 				: 	fclean
					make all

.PHONY 			: 	all clean fclean re