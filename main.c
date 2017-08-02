/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 12:48:22 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/02 20:00:05 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

char				*creat_path(char *argv, char *d_name)
{
	char	*path;
	size_t	len;

	len	= ft_strlen(argv) + 2 + ft_strlen(d_name);
	path = ft_strnew(len);
	path = ft_strcpy(path, argv);
	path = ft_strcat(path, "/");
	path = ft_strcat(path, d_name);
	return (path);
}

static t_path		*ft_init(struct dirent *sd, char *argv, t_ops ops, DIR *dir)
{
	struct stat		buff;
	t_path			*list;
	t_data 			*data;

	list = NULL;
	while ((sd = readdir(dir)))
	{
		if (lstat(creat_path(argv, sd->d_name), &buff) == 0)
		{
			if (ops.a_option == false && *sd->d_name == '.')
				;
			else
			{
				data = init_data(&buff, sd);
				if (!list)
						list = add_head(list, data);
				else
					insert_ascii(&list, create_node(data));
			}
		}
		else
			perror("ft_ls");
	}
	return (list);
}

t_path				*list_file(char *argv, t_ops ops)
{
	DIR				*dir;
	struct dirent	*sd;
	struct stat		buff;
	t_data			*data;
	t_path			*list;

	dir = opendir(argv);
	list = NULL;
	if (!dir)
	{
		perror("ft_ls ");
		return (NULL);
	}
	list = ft_init(sd, argv, ops, dir);
	return (list);
}

int					main(int argc, char **argv)
{
	t_path	*list;
	t_path	*list_args;
	t_ops	flags;

	list_args = NULL;
	list = NULL;
	if (argc > 1)
	{
		flags = parsing_option(argc, argv);
		list_args = sort_argv(argc, argv, flags);
		// list = list_file(argv[1], flags);
		print_list(list);
	}
	return (0);
}
