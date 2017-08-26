# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhallyn <juhallyn@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 18:24:18 by juhallyn          #+#    #+#              #
#    Updated: 2017/08/26 08:50:45 by juhallyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

OBJS	=	$(SRC:.c=.o)

INCLUDE	=	Includes/

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
	@gcc $(FLAG) $(OBJS) -I $(INCLUDE) $(LIB)libft.a -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make fclean -C $(LIB)

fclean: clean
	@rm -f $(NAME)

re: fclean all
