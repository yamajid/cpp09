# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 21:28:56 by yamajid           #+#    #+#              #
#    Updated: 2024/03/17 03:36:39 by yamajid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	btc
Run		=	c++ -g
FLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -f

SRCS 	=	 main.cpp BitcoinExchange.cpp

otherS = $(SRCS:.cpp=.o)

all: $(NAME)
%.o: %.cpp
	$(Run) $(FLAGS) -c $< -o $@

$(NAME): $(otherS) BitcoinExchange.hpp
	$(Run) $(FLAGS) -o $(NAME) $(otherS)

clean:
	$(RM) $(otherS)
fclean: clean
	$(RM) $(NAME) 

re: fclean all