/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 16:20:17 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/14 16:20:44 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

char	*link_name(char *path)
{
	char		buff[1024];

	if (readlink(path, buff, 1024))
		return (ft_strdup(buff));
	return (NULL);
}
