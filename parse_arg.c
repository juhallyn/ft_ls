/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 11:51:11 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/06 14:34:59 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

void	separe_folders_files(t_path *list_args, t_path **dirs, t_path **others,\
		t_ops ops)
{
	struct stat	buff;

	while (list_args)
	{
		if (lstat(FILE, &buff) == 0)
		{
			if (filetype(&buff) == 'd')
			{
				if (!*dirs)
					*dirs = add_head(*dirs, init_data(&buff, FILE));
				else
					chose_insert(dirs, NODE(init_data(&buff, FILE)), ops);
			}
			else
			{
				if (!*others)
					*others = add_head(*others, init_data(&buff, FILE));
				else
					chose_insert(others, NODE(init_data(&buff, FILE)), ops);
			}
		}
		else
			perror(ft_error(FILE));
		list_args = list_args->next;
	}
}

void	open_arg(t_path *dirs, t_path *others, t_ops ops, int nb_arg)
{
	if (others)
	{
		if (ops.l_option == true)
			print_list(others, false);
		else
			simple_print(others);
		if (dirs)
			ft_putchar('\n');
	}
	while (dirs && ops.R_option == false)
	{
		if (nb_arg > 1)
			ft_putfolder(FOLDER);
		if (ops.l_option == true)
			print_list(list_file(FOLDER, ops), true);
		else
			simple_print(list_file(FOLDER, ops));
		if (dirs->next)
			ft_putchar('\n');
		dirs = dirs->next;
	}
	if (ops.R_option == true)
		recursive(dirs, ops, nb_arg);
}

t_data	*init_argv_data(char *str)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		exit(-1);
	data->d_name = ft_strdup(str);
	return (data);
}

t_path	*sort_argv(int argc, char **argv, t_ops ops)
{
	t_data	*data;
	t_path	*list;
	int		i;

	i = 1;
	list = NULL;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			;
		else
		{
			data = init_argv_data(argv[i]);
			list = add_end(list, data);
		}
		i++;
	}
	return (list);
}
