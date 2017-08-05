/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 12:42:42 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/05 15:20:01 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

int		recursive(t_path *dirs, t_ops ops)
{
	struct dirent	sd;
	struct stat		buff;
	t_path			*rec;
	t_path			*dirs_in_dir;
	DIR				*curent_dir;

	dirs_in_dir = NULL;
	rec = NULL;
	while (dirs)
	{
		curent_dir = opendir(FOLDER);
		if (!curent_dir)
			perror("ft_ls ");
		rec = ft_init(&sd, FOLDER, ops, curent_dir);
		// chose_print(rec, ops);
		while (rec)
		{
			if (lstat(rec->data->d_name, &buff) == 0)
			{
				if (filetype(&buff) == 'd')
					dirs_in_dir = add_end(dirs_in_dir, rec->data);
			}
			while (dirs_in_dir)
			{
				ft_putendl(dirs_in_dir->data->d_name);
				dirs_in_dir = dirs_in_dir->ne
			}
			rec = rec->next;
		}
		closedir(curent_dir);
		dirs = dirs->next;
	}
	return (0);
}
