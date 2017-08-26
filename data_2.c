/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 16:20:17 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/26 08:51:30 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_ls.h"

char	*link_name(char *path)
{
	char		buff[1024];

	ft_memset(buff, '\0', 1024);
	if (readlink(path, buff, 1023))
		return (ft_strdup(buff));
	return (NULL);
}

void	sticky_bits(struct stat *buff, char *permission)
{
	if (buff->st_mode & S_ISUID)
		permission[3] = (buff->st_mode & S_IXUSR) ? 's' : 'S';
	if (buff->st_mode & S_ISGID)
		permission[6] = (buff->st_mode & S_IXGRP) ? 's' : 'l';
	if (buff->st_mode & S_ISVTX)
		permission[9] = (buff->st_mode & S_IXOTH) ? 't' : 'T';
}
