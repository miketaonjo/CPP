# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 18:34:52 by mcloarec          #+#    #+#              #
#    Updated: 2023/01/30 16:51:33 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ScavTrap

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98 -g

INC		= -I ./includes/

SRCS	= srcs/main.cpp \
		  srcs/ClapTrap.cpp \
		  srcs/ScavTrap.cpp

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
