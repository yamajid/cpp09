# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 21:28:56 by yamajid           #+#    #+#              #
#    Updated: 2024/03/17 03:26:34 by yamajid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	RPN
Run		=	c++ -g
FLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -f

SRCS 	=	 main.cpp 

otherS = $(SRCS:.cpp=.o)

all: $(NAME)
%.o: %.cpp
	$(Run) $(FLAGS) -c $< -o $@

$(NAME): $(otherS) RPN.hpp
	$(Run) $(FLAGS) -o $(NAME) $(otherS)

clean:
	$(RM) $(otherS)
fclean: clean
	$(RM) $(NAME) 

re: fclean all