# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 14:55:09 by galambey          #+#    #+#              #
#    Updated: 2024/02/02 13:44:23 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	./phonebook

SRCS_DIR	=	srcs/

SRCS		=	PhoneBook.cpp\
				Contact.cpp\
				main.cpp

OBJS_DIR	=	.objs/

OBJS_NAMES	=	$(SRCS:.cpp=.o)

OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_NAMES))

DEPS		=	$(OBJS:.o=.d)

CC			=	c++

CPP_FLAGS	=	-Wall -Wextra -Werror -MMD -std=c++98

#################################### RULES ####################################

all 			: 	$(NAME)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.cpp
					mkdir -p $(@D)
					$(CC) $(CPP_FLAGS) -c $< -o $@
		
$(NAME) 		: 	$(OBJS)
					$(CC) $(CPP_FLAGS) $(OBJS) -o $@

-include $(DEPS)

clean 			:
					rm -rf $(OBJS_DIR)

fclean 			: 	clean
					rm -f $(NAME)

re 				: 	fclean
					make -j all

.PHONY 			: 	all clean fclean re