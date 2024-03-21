# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 04:16:26 by jbettini          #+#    #+#              #
#    Updated: 2024/03/21 05:20:51 by jbettini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g
RM 			= 	rm -f
NAME		=	lem-in
SRC			=	srcs/${wildcard *.c}
LIBFT_DIR	=	libft

TXT_RED = "\033[1;31m"
TXT_GREEN = "\033[1;32m"
TXT_YELLOW = "\033[1;33m"
TXT_BLUE = "\033[1;34m"
TXT_MAGENTA = "\033[1;35m"
TXT_CYAN = "\033[1;36m"
FANCY_RESET = "\033[0m"

OBJ		=	$(SRC:%.cpp=%.o)

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ -c $< 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	make -C clean $(LIBFT_DIR)
	rm -rf $(OBJ)

fclean: clean
	make -C fclean $(LIBFT_DIR)
	rm  -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re