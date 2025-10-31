# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 14:39:29 by chhoflac          #+#    #+#              #
#    Updated: 2025/10/31 16:46:06 by chhoflac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SOURCES = main.cpp \
		RPN.cpp
		
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