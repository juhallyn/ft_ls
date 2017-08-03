/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 08:41:42 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/03 19:12:27 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

void 		ft_putentab(char *str)
{
	write(1, str, ft_strlen(str));
	ft_putchar('\t');
}

char		*ft_error(char *name)
{
	char 	*error;

	error = ft_strjoin("ft_ls: ", name);
	return (error);
}

void		ft_putfolder(const char *s1)
{
	ft_putstr(s1);
	ft_putendl(":");
}

blkcnt_t	all_blocks(t_path *list)
{
	blkcnt_t	total;
	t_path		*tmp;

	total = 0;
	tmp = list;
	while (tmp)
	{
		total = total + tmp->data->blocks;
		tmp = tmp->next;
	}
	write(1, "total ", 6);
	return (total);
}

void		print_blocks(blkcnt_t blocks)
{
	ft_putnbr(blocks);
	ft_putchar('\n');
}
