/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:41:32 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/15 20:09:14 by juhallyn         ###   ########.fr       */
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

void	print_symlink(char *d_name, char *path)
{
	ft_putstr(d_name);
	ft_putstr(" -> ");
	ft_putendl(link_name(path));
}

void	chose_print(t_path *list, t_ops ops, bool total)
{
	if (ops.l_option == false)
		simple_print_reverse(list, ops);
	else
		print_list_reverse(list, list, total, ops);
}

bool	current_and_before_folder(char *d_name)
{
	if (ft_strcmp(".", d_name) == 0 || ft_strcmp("..", d_name) == 0)
		return (true);
	return (false);
}

t_path	*init_path(char *path)
{
	struct stat		buff;
	t_path			*dir;

	dir = NULL;
	if (lstat(path, &buff) == 0)
		dir = create_node(init_data(&buff, path, path));
	return (dir);
}
