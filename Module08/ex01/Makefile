# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 16:23:53 by mcloarec          #+#    #+#              #
#    Updated: 2023/03/10 06:04:51 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ex01

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98 -g3

INC		= -I ./includes/

SRCS	= 	srcs/main.cpp \
			srcs/Span.cpp

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
