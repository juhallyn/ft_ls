# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 18:24:18 by juhallyn          #+#    #+#              #
#    Updated: 2017/08/18 13:56:19 by juhallyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_Colors_#

#GREEN	=	echo "\x1b[32m $1 \x1b[0m $2"

#PURPLE	=	echo "\x1b[35m $1 \x1b[0m $2"

#_Files_#

NAME	=	ft_ls

SOURCES =	data.c			\
			main.c			\
			data_2.c		\
			init_data.c		\
			list.c			\
			option.c		\
			parse_arg.c		\
			print.c			\
			recursive.c		\
			sort.c			\
			tools.c			\
			tools2.c		

OBJS	=	$(SOURCES:.c=.o)

LIB		=	libft/

#_Compilation_#

FLAG 	=	-Wall -Wextra -Werror -Ofast

all: $(NAME)

norm:
	@clear
	@norminette $(SOURCES)

#_Compilation_#

$(NAME):
	@echo "\033[37;44m Make libft \033[0m"
	@make -C $(LIB)
	@echo "\033[37;44m Make ft_ls \033[0m"
	@gcc $(FLAG) -c $(SOURCES)
	@gcc $(FLAG) $(OBJS) $(LIB)libft.a -o $(NAME)
	@echo "\033[37;44m done [√] \033[0m"


clean:
	@echo "\033[37;44m clear \033[0m"
	@rm -f $(OBJS)
	@make clean -C $(LIB)
	@(cd $(LIB) && $(MAKE) $@)

fclean:
	@echo "\033[37;44m fclean \033[0m"
	@make fclean -C $(LIB)
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all
