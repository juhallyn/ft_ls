/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 11:51:11 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/02 19:38:57 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

bool		file_exists(const char* file)
{
    struct stat buff;
    return (lstat(file, &buff) == 0);
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
