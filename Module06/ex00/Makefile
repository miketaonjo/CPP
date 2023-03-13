# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 12:09:46 by mcloarec          #+#    #+#              #
#    Updated: 2023/02/22 18:15:24 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= convert

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98 -g3

INC		= -I ./includes/

SRCS	= srcs/main.cpp \
		  srcs/ScalarConverter.cpp \

OBJS	= $(SRCS:.cpp=.o)

RM		= rm -rf

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)
	@echo "compilation completed"

clean:
	$(RM) $(OBJS)
	@echo "clean done"

fclean: clean
	$(RM) $(NAME)
	@echo "fclean done"

re: fclean all

.SILENT:

.PHONY: all re clean fclean
