/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:06:41 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/03 16:22:14 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

t_data		*init_data(struct stat *buff, struct dirent *sd)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		exit(-1);
	data->permission = permission(buff);
	data->hard_link = buff->st_nlink;
	data->owner = ft_strdup(owner(buff));
	data->group = ft_strdup(group(buff));
	data->file_size = buff->st_size;
	data->time = ft_time(buff);
	data->d_name = ft_strdup(sd->d_name);
	data->blocks = buff->st_blocks;
	return (data);
}
