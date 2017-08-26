/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 12:42:42 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/26 08:52:19 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_ls.h"

void			recursive(t_path *dirs, t_ops ops)
{
	char		*name;

	while (dirs)
	{
		name = dirs->data->d_name;
		ft_putfolder(name);
		dirs_in_dir(list_file(name, ops), name, ops);
		dirs = dirs->next;
		if (dirs)
			ft_putchar('\n');
	}
}

void			do_recursive(t_path *directories, char *old_name, t_ops ops)
{
	char	*path;
	t_path	*tmp;

	if (!directories)
		return ;
	tmp = directories;
	while (tmp)
	{
		if (current_and_before_folder(tmp->data->d_name) == true)
			;
		else
		{
			path = creat_path(old_name, tmp->data->d_name);
			ft_putchar('\n');
			if (ft_strncmp("//", path, 2) == 0)
				(void)*path++;
			ft_putfolder(path);
			dirs_in_dir(list_file(path, ops), path, ops);
		}
		tmp = tmp->next;
	}
}

void			dirs_in_dir(t_path *containt, char *name, t_ops ops)
{
	struct stat		buff;
	t_path			*dirs_in;

	if (!containt)
		return ;
	chose_print(containt, ops);
	dirs_in = NULL;
	while (containt)
	{
		if (lstat(creat_path(name, CONTAINT_NAME), &buff) == 0)
		{
			if (filetype(&buff) == 'd')
			{
				dirs_in = add_end(dirs_in, init_data(&buff, \
				CONTAINT_NAME, creat_path(name, CONTAINT_NAME)));
			}
		}
		else
			perror(ft_error(creat_path(name, CONTAINT_NAME)));
		containt = containt->next;
	}
	do_recursive(dirs_in, name, ops);
	return ;
}
