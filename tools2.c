/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:41:32 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/12 23:05:23 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

void	print_major_minor(dev_t device)
{
	ft_putnbr(major(device));
	ft_putchar(',');
	ft_putchar('\t');
	ft_putnbr(minor(device));
}

void		chose_print(t_path *list, t_ops ops)
{
	if (ops.l_option == false)
		simple_print(list);
	else
		print_list(list, false);
}

bool		current_and_before_folder(char *d_name)
{
	if (ft_strcmp(".", d_name) == 0 || ft_strcmp("..", d_name) == 0)
		return (true);
	return (false);
}

t_path		*init_path(char *path)
{
	struct	stat	buff;
	t_path			*dir;

	dir = NULL;
	if (lstat(path, &buff) == 0)
		dir = add_head(dir, init_data(&buff, path));
	return (dir);
}
