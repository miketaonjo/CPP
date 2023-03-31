# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 18:11:30 by mcloarec          #+#    #+#              #
#    Updated: 2023/02/09 08:04:51 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Animals

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98

INC		= -I ./includes/

SRCS	= srcs/main.cpp \
		  srcs/Animal.cpp \
		  srcs/Cat.cpp \
		  srcs/Dog.cpp \
		  srcs/WrongAnimal.cpp \
		  srcs/WrongCat.cpp \

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
