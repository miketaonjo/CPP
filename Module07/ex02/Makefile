# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 17:50:09 by mcloarec          #+#    #+#              #
#    Updated: 2023/03/05 16:22:04 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ex02

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98

INC		= -I ./includes/

SRCS	= srcs/main.cpp

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
