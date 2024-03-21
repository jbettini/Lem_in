# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 05:04:25 by jbettini          #+#    #+#              #
#    Updated: 2024/03/21 05:06:48 by jbettini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ${wildcard *.c}

OBJS = ${SRCS:.c=.o}

CC = clang
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

TXT_RED = "\033[1;31m"
TXT_GREEN = "\033[1;32m"
TXT_YELLOW = "\033[1;33m"
TXT_BLUE = "\033[1;34m"
TXT_MAGENTA = "\033[1;35m"
TXT_CYAN = "\033[1;36m"
FANCY_RESET = "\033[0m"

%.o: %.c
	@printf  $(TXT_GREEN)"\rCompilation des fichiers source de la libft : "$(TXT_CYAN)" $<         "$(FANCY_RESET)
	@${CC} ${CFLAGS} -o $@ -c $< > /dev/null 2>&1

${NAME}: ${OBJS}
	@echo $(TXT_GREEN)
	@echo "Création de l'archive ${NAME} ..."
	@${AR} ${NAME} ${OBJS} > /dev/null 2>&1
	@echo "Archive ${NAME} crée."
	@echo $(FANCY_RESET)

all:	${NAME} 

clean:
	@printf  $(TXT_RED)"Archive libft.a supprimé\n"$(FANCY_RESET)
	@${RM} ${OBJS} > /dev/null 2>&1

fclean:	clean
		@${RM} ${NAME} > /dev/null 2>&1

re:	fclean all

.PHONY: all clean fclean re
