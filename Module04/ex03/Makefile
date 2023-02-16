# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 14:03:25 by mcloarec          #+#    #+#              #
#    Updated: 2023/02/13 18:20:10 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= AMateria

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98 -g3

INC		= -I ./includes/

SRCS	= srcs/AMateria.cpp \
		  srcs/Character.cpp \
		  srcs/Cure.cpp \
		  srcs/Ice.cpp \
		  srcs/MateriaSource.cpp \
		  srcs/main.cpp \

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
