/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 12:48:22 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/24 16:14:00 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

static void			add_to_list(t_path **list, t_data *data, t_ops ops)
{
	t_path	*new;

	new = create_node(data);
	if (!*list)
		*list = new;
	else
		chose_insert(list, new, ops);
}

t_path				*ft_init(struct dirent *sd, char *argv, t_ops ops, DIR *dir)
{
	struct stat		buff;
	t_path			*list;
	t_data			*data;
	char			*path;

	list = NULL;
	while ((sd = readdir(dir)))
	{
		if ((lstat(path = (creat_path(argv, sd->d_name)), &buff) == 0))
		{
			if (ops.a_option == false && *sd->d_name == '.')
				;
			else
			{
				data = init_data(&buff, sd->d_name, path);
				add_to_list(&list, data, ops);
			}
		}
		else
			perror(ft_error(argv));
	}
	return (list);
}

t_path				*list_file(char *argv, t_ops ops)
{
	DIR				*dir;
	struct dirent	*sd;
	t_path			*list;

	sd = NULL;
	dir = opendir(argv);
	list = NULL;
	if (!dir)
	{
		perror(ft_error(argv));
		return (NULL);
	}
	else
	{
		list = ft_init(sd, argv, ops, dir);
		if (closedir(dir) == -1)
		{
			perror(ft_error(argv));
			return (NULL);
		}
	}
	return (list);
}

static void			ft_select(int argc, char **argv, int nb_arg, t_ops ops)
{
	t_path	*list_args;
	t_path	*dirs;
	t_path	*others;

	list_args = NULL;
	dirs = NULL;
	others = NULL;
	if (nb_arg == 0 && ops.recurse_option == true)
		open_arg(init_path("."), NULL, ops, 0);
	else if (nb_arg == 0)
		chose_print(list_file(".", ops), ops);
	else
	{
		list_args = sort_argv(argc, argv);
		separe_folders_files(list_args, &dirs, &others, ops);
		open_arg(dirs, others, ops, nb_arg);
	}
}

int					main(int argc, char **argv)
{
	t_ops	ops;
	int		nb_arg;

	nb_arg = -1;
	ops = parsing_option(argc, argv, &nb_arg);
	if (argc > 1)
		ft_select(argc, argv, nb_arg, ops);
	else
		simple_print(list_file(".", ops));
	return (0);
}
