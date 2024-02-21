# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 09:15:04 by galambey          #+#    #+#              #
#    Updated: 2024/02/20 15:21:12 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fixed

SRCS_DIR 	= 	srcs/

SRCS 		= 	main.cpp \
	   			Fixed.cpp

OBJS_DIR 	= 	objs/

OBJS_NAME 	= 	$(SRCS:.cpp=.o)

OBJS 		= 	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

CXX 		= 	c++

CXXFLAGS 	= 	-Wall -Wextra -Werror -std=c++98 -g3

#################################### RULE #####################################

all		 		: 	$(NAME)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.cpp
					mkdir -p $(@D)
					$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) 		:	$(OBJS)
					$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean			:
					rm -rf $(OBJS_DIR)

fclean			:	clean
					rm -f $(NAME)

re 				:	fclean
					make all

.PHONY			: all clean fclean re