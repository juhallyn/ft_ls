# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhallyn <juhallyn@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 18:24:18 by juhallyn          #+#    #+#              #
#    Updated: 2017/08/24 17:26:01 by juhallyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_Colors_#

GREEN	=	echo "\x1b[32m $1 \x1b[0m $2"

PURPLE	=	echo "\x1b[35m $1 \x1b[0m $2"

#_Files_#

NAME	=	ft_ls

SRC	=		data.c			\
			data_2.c		\
			init_data.c		\
			list.c			\
			main.c			\
			option.c		\
			parse_arg.c		\
			print.c			\
			recursive.c		\
			sort.c			\
			sort_rev.c		\
			tools.c			\
			tools2.c		\

OBJS = $(SRC:.c=.o)

LIB		=	libft/

#_Compilation_#

FLAG 	=	-Wall -Wextra -Werror

all: $(NAME)

norm:
	@clear
	@norminette $(SRC)

#_Compilation_#

$(NAME):
	@make -C $(LIB)
	@gcc $(FLAG) -c $(SRC)
	@gcc $(FLAG) $(SRC) $(LIB)libft.a -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make fclean -C $(LIB)

fclean: clean
	@rm -f $(NAME)

re: fclean all
