# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhallyn <juhallyn@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 18:24:18 by juhallyn          #+#    #+#              #
#    Updated: 2017/07/29 14:11:16 by juhallyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_Colors_#

GREEN	=	echo "\x1b[32m $1 \x1b[0m $2"

PURPLE	=	echo "\x1b[35m $1 \x1b[0m $2"

#_Files_#

NAME	=	ft_ls

SRC 	=	data.c			\
			init_data.c		\
			list.c			\
			main.c			\
			option.c		\
			print.c			\
			sort.c			\
			tools.c			\

OBJ		=	$(SRC:.c=.o)

LIB		=	libft/

#_Compilation_#

FLAG 	=	#-Wall -Wextra -Werror

all: $(NAME)

norm:
	@clear
	@norminette $(SRC)

#_Compilation_#

$(NAME):
	@gcc $(FLAG) -c $(SRC)
	make -C $(LIB)
	@gcc $(OBJ) libft/libft.a  -o $(NAME)

clean:
	@rm -f $(OBJ)
	@(cd $(LIB) && $(MAKE) $@)

fclean:
	make fclean -C $(LIB)
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all
