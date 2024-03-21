# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 09:38:17 by galambey          #+#    #+#              #
#    Updated: 2024/03/20 17:23:38 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	convert

SRCS_DIR			=	srcs/

SRCS				=	main.cpp \
						ScalarConverter.cpp \
						AConverter.cpp \
						CharConverter.cpp \
						IntConverter.cpp \
						DoubleConverter.cpp \
						FloatConverter.cpp

OBJS_DIR			=	.objs/

OBJS_NAME		=	$(SRCS:.cpp=.o)

OBJS				=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

DEPS				=	$(OBJS:.o=.d)

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

test			:	re
					echo
					valgrind ./convert
					echo
					valgrind ./convert 1 1
					echo
					valgrind ./convert 0
					echo
					valgrind ./convert a
					echo
					valgrind ./convert ""
					echo
					valgrind ./convert 10
					echo
					valgrind ./convert 127
					echo
					valgrind ./convert 128
					echo
					valgrind ./convert 00
					echo
					valgrind ./convert -1
					echo
					valgrind ./convert -128
					echo
					valgrind ./convert -129
					echo
					valgrind ./convert 42
					echo
					valgrind ./convert 2147483647
					echo
					valgrind ./convert 2147483648
					echo
					valgrind ./convert -2147483648
					echo
					valgrind ./convert -2147483649
					echo
					valgrind ./convert 42.0f
					echo
					valgrind ./convert .0f
					echo
					valgrind ./convert 0.f
					echo
					valgrind ./convert 0.0f
					echo
					valgrind ./convert 5.0f
					echo
					valgrind ./convert -2147483648.0f
					echo
					valgrind ./convert 2147483648.0f
					echo
					valgrind ./convert nanf
					echo
					valgrind ./convert +inff
					echo
					valgrind ./convert -inff
					echo
					valgrind ./convert 340282000000000000000000000000000000000.f
					echo
					valgrind ./convert 3402820000000000000000000000000000000000.f
					echo
					valgrind ./convert -340282000000000000000000000000000000000.f
					echo
					valgrind ./convert -3402820000000000000000000000000000000000.f
					echo
					valgrind ./convert -98.05ff
					echo
					valgrind ./convert nan
					echo
					valgrind ./convert +inf
					echo
					valgrind ./convert -inf
					echo
					valgrind ./convert -98.31aaa
					echo
					valgrind ./convert 99.31568
					echo
					valgrind ./convert .3156
					echo
					valgrind ./convert 98.
					echo
					valgrind ./convert ..
					echo
					valgrind ./convert .02.
					echo
					valgrind ./convert -3402820000000000000000000000000000000000.0
					echo
					valgrind ./convert 179769000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.
					echo
					valgrind ./convert 1797690000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.
					echo
					valgrind ./convert -179769000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0
					echo
					valgrind ./convert -1797690000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0
					echo
					valgrind ./convert hello
					
clean			:
					rm -rf $(OBJS_DIR)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean
					make all

.PHONY			:	all test clean fclean re