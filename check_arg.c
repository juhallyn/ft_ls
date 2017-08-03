/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 11:51:11 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/03 15:24:10 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"
// {
// 	if (argc > 2 && filetype(&buff) == 'd')
// 		ft_putfolder(FILE);
// 	if (filetype(&buff) == 'd')
// 	{
// 		print_list(list_file(FILE, ops));
// 		if (argc > 2 && list_args->next && )
// 			ft_putchar('\n');
// 	}
// }

void		open_arg(t_path *list_args, t_ops ops, int argc)
{
	struct stat buff;
	int			i;

	i = 0;
	while (list_args)
	{
		if (lstat(FILE, &buff) == 0)
		{
			if (filetype(&buff) == 'd')
		}
		else
			perror(ft_error(FILE));
		list_args = list_args->next;
	}
}

int			nb_folders(t_path *list_args)
{
	int	i;

	i = 0;
	while (list_args)
	{
		if (lstat(file))
	}
}

t_data		*init_argv_data(char *str)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		exit(-1);
	data->d_name = ft_strdup(str);
	return (data);
}

t_path		*sort_argv(int argc, char **argv, t_ops ops)
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
			if (!list)
				list = add_head(list, data);
			else
				insert_ascii(&list, create_node(data));
		}
		i++;
	}
	return (list);
}
