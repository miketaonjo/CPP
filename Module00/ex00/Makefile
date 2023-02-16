# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 11:30:18 by mcloarec          #+#    #+#              #
#    Updated: 2023/01/05 15:51:23 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98

SRC		= megaphone.cpp

OBJ		= $(SRC:.cpp=.o)

RM		= rm -rf

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "compilation completed"

clean:
	$(RM) $(OBJ)
	@echo "clean done"

fclean: clean
		$(RM) $(NAME)
		@echo "fclean done"

re: fclean all

.SILENT:

.PHONY: all re clean fclean
