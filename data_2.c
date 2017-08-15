/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 16:20:17 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/15 10:52:54 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

char	*link_name(char *path)
{
	char		buff[1024];

	ft_memset(buff, '\0', 1024);
	if (readlink(path, buff, 1023))
	{
		return (ft_strdup(buff));
	}
	return (NULL);
}
