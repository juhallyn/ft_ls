/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 10:02:04 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/26 08:51:55 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_ls.h"

int			error_option(char bad_option)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(bad_option, 2);
	ft_putendl_fd("\nusage: ls [-lRart] [file ...]", 2);
	exit(-1);
}

int			check_options(char *options)
{
	int		i;

	i = 1;
	if (options[i] == '-')
		;
	else
	{
		while (options[i])
		{
			if (options[i] != 'l' && options[i] != 'R' && options[i] != 'a' && \
			options[i] != 'r' && options[i] != 't')
				error_option(options[i]);
			i++;
		}
	}
	return (0);
}

void		init_flags(char *options, t_ops **flags)
{
	int i;

	i = 0;
	while (options[i])
	{
		if (options[i] == 'a')
			(*flags)->a_option = true;
		if (options[i] == 'R')
			(*flags)->recurse_option = true;
		if (options[i] == 't')
			(*flags)->t_option = true;
		if (options[i] == 'l')
			(*flags)->l_option = true;
		if (options[i] == 'r')
			(*flags)->r_option = true;
		i++;
	}
}

t_ops		parsing_option(int argc, char **argv, int *nb_arg)
{
	int		i;
	t_ops	*flags;

	i = 0;
	flags = (t_ops*)malloc(sizeof(t_ops));
	if (!flags)
		exit(-1);
	ft_memset(flags, 0, sizeof(t_ops));
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			check_options(argv[i]);
			init_flags(argv[i], &flags);
		}
		else
			*nb_arg = *nb_arg + 1;
		i++;
	}
	return (*flags);
}
