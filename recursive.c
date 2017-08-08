/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 12:42:42 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/08 17:18:27 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"
/*
static t_path	*return_directories(t_path *content, t_ops ops)
{
	t_path			*list_dirs;
	struct stat		buff;
	t_data			*data;
	char 			*name;

	data = init_data(&buff, name);
	while (content)
	{
		name = content->data->d_name;
		if (lstat(name, &buff) == 0)
		{
			if (filetype(&buff) == 'd')
				list_dirs = add_end(list_dirs, data);
		}
		content = content->next;
	}
	return (list_dirs);
}

int				recursive(t_path *dirs, t_ops ops, int nb_arg)
{
	struct stat		buff;
	struct dirent	sd;
	DIR				*current;
	t_path			*content;
	t_path			*list_dirs;
	char			*name;

	while (dirs)
	{
		current = opendir(FOLDER);
		if (!current)
			perror(ft_error(FOLDER));
		else
			content = ft_init(&sd, FOLDER, ops, current);
		dirs = dirs->next;
	}
	// chose_print(content, ops);
	list_dirs = return_directories(content, ops);
	// chose_print(list_dirs, ops);
	return (0);
}

*/

