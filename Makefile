# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/04/22 02:46:42 by ccorazza          #+#    #+#              #
#    Updated: 2014/05/18 13:36:31 by ccorazza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

include Makefile.sources

OBJ = $(SRC:.c=.o)
GW = @clang -Wall -Wextra -Werror -g
LFLAGS =  -L/usr/X11/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	@printf "Début de la compilation...\r"
	@make -C libft/
	@printf "Début de la compilation...\r"
	$(GW) $(LFLAGS) -Llibft -lft -o $(NAME) $(OBJ)
	@echo "... Compilation de Wolf3d [\033[38;5;34mDone\033[0m].\n"
	@echo "\t\033[36m- Usage -\n\033[0m"
	@echo "./wolf3d nom_de_la_map\n"

$(OBJ):
	$(GW) -I/usr/X11/include -Ilibft -c $(SRC)

clean:
	@echo "\033[36mSuppression des .o\033[0m"
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@echo "\033[35mSuppression de l'exécutable\033[0m"
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
	@echo "Tout frais, tout propre !"

.PHONY: all, clean, fclean, re

help:
	@printf '\033[1;33m%6s \033[0m⇒ %s\n' "clean"	"Suppression des .o"
	@printf '\033[1;33m%6s \033[0m⇒ %s\n' "fclean"	"Rappelle 'clean' && supprime l'exécutable"
	@printf '\033[1;33m%6s \033[0m⇒ %s\n' "re"		"Appelle clean, fclean, et recompile"
