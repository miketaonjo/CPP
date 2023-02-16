# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:05:55 by mcloarec          #+#    #+#              #
#    Updated: 2023/02/10 14:51:50 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Animals

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98 -g

INC		= -I ./includes/

SRCS	= srcs/main.cpp \
		  srcs/Animal.cpp \
		  srcs/Cat.cpp \
		  srcs/Dog.cpp \
		  srcs/WrongAnimal.cpp \
		  srcs/WrongCat.cpp \
		  srcs/Brain.cpp \

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
