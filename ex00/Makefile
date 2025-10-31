# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 14:35:45 by chhoflac          #+#    #+#              #
#    Updated: 2025/10/31 13:54:31 by chhoflac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

SOURCES = main.cpp \
		BitcoinExchange.cpp \
		BadInputException.cpp \
		NotPositiveException.cpp \
		TooLargeNumberException.cpp \
		Date.cpp
		
OBJS = $(SOURCES:.cpp=.o)

RM = rm -rf

CXX = c++

CPPFLAGS = -Werror -Wextra -Wall -std=c++98

all: $(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re