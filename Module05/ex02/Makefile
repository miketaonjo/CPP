# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:49:41 by mcloarec          #+#    #+#              #
#    Updated: 2023/02/16 18:44:35 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Bureaucracy

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98

INC		= -I ./includes/

SRCS	= srcs/main.cpp \
		  srcs/Bureaucrat.cpp \
		  srcs/Form.cpp \
		  srcs/ShrubberyCreationForm.cpp \
		  srcs/RobotomyRequestForm.cpp \
		  srcs/PresidentialPardonForm.cpp

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
