# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 13:59:29 by mcloarec          #+#    #+#              #
#    Updated: 2023/01/27 16:55:51 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ClapTrap

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98 -g

INC		= -I ./includes/

SRCS	= srcs/main.cpp \
		  srcs/ClapTrap.cpp

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
