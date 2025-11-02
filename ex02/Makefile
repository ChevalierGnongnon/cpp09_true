# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 14:08:34 by chhoflac          #+#    #+#              #
#    Updated: 2025/11/02 16:41:10 by chhoflac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SOURCES = main.cpp \
		PMergeMe.cpp
		
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