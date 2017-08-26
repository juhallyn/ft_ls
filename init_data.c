/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:06:41 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/26 08:51:40 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_ls.h"

char	*creat_path(char *argv, char *d_name)
{
	char	*path;
	size_t	len;

	if (!argv || !d_name)
		return (NULL);
	len = ft_strlen(argv) + 2 + ft_strlen(d_name);
	path = ft_strnew(len);
	path = ft_strcpy(path, argv);
	path = ft_strcat(path, "/");
	path = ft_strcat(path, d_name);
	return (path);
}

t_data		*init_data(struct stat *buff, char *name, char *path)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		exit(-1);
	data->min_maj = false;
	data->is_symlink = filetype(buff) == 'l' ? true : false;
	data->permission = permission(buff);
	data->hard_link = buff->st_nlink;
	data->owner = ft_strdup(owner(buff));
	data->group = ft_strdup(group(buff));
	data->file_size = buff->st_size;
	data->time = ft_time(buff);
	data->d_name = ft_strdup(name);
	data->blocks = buff->st_blocks;
	data->path = ft_strdup(path);
	data->symlink = link_name(path);
	data->modif_time = buff->st_mtimespec.tv_sec;
	if (filetype(buff) == 'c' || filetype(buff) == 'b')
	{
		data->device = buff->st_rdev;
		data->min_maj = true;
	}
	return (data);
}
