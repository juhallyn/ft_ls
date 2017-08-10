/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 12:42:42 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/10 05:10:06 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

int				recursive(t_path *dirs, t_ops ops, int nb_arg)
{
	t_path		*directories;

	directories = ft_open(dirs, ops);
	return (0);
}

t_path			*ft_open(t_path *dirs, t_ops ops)
{
	struct stat buff;
	t_path		*all;
	t_path		*containt;
	char		*name;

	while (dirs)
	{
		name = dirs->data->d_name;
		ft_putendl(name);
		dirs_in_dir(list_file(dirs->data->d_name, ops), name, ops);
		dirs = dirs->next;
	}
	// chose_print(directories, ops);
	return (NULL);
}

int			do_recursive(t_path *directories, char *old_name, t_ops ops)
{
	char	*path;
	t_path	*tmp;

	tmp = directories;
	while (tmp)
	{
		ft_putfolder(tmp->data->d_name);
		path = creat_path(old_name, tmp->data->d_name);
		ft_putendl(path);
		dirs_in_dir(list_file(path, ops), path, ops);
		tmp = tmp->next;
	}
	// if (tmp->next)
	// 	dirs_in_dir(list_file(path, ops), path, ops);
	// if (directories->next)
	// {
	// 	ft_putendl(path);
	//  	dirs_in_dir(list_file(path, ops), path, ops);
	// }
	return (0);
}

t_path		*dirs_in_dir(t_path *containt, char *name, t_ops ops)
{
	struct	stat	buff;
	t_path			*dirs_in_dir;

	if (!containt)
		return (NULL);
	chose_print(containt, ops);
	while (containt)
	{
		lstat(creat_path(name, containt->data->d_name), &buff);
		if (filetype(&buff) == 'd')
		{
			dirs_in_dir = add_end(dirs_in_dir, init_data(&buff, \
			containt->data->d_name));
		}
		containt = containt->next;
	}
	do_recursive(dirs_in_dir, name, ops);
	return (NULL);
}
