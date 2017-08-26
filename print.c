/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 19:37:58 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/26 08:52:09 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_ls.h"

void			print_list(t_path *list, t_bool total)
{
	t_path	*tmp;
	t_bool	block;

	block = true;
	tmp = list;
	while (tmp)
	{
		if (block == true && total == true)
			print_blocks(all_blocks(list));
		block = false;
		ft_putentab(tmp->data->permission);
		ft_putnbr(tmp->data->hard_link);
		ft_putchar('\t');
		ft_putentab(tmp->data->owner);
		special_print(tmp);
		tmp = tmp->next;
	}
}

void			simple_print(t_path *list)
{
	t_path *tmp;

	tmp = list;
	while (tmp)
	{
		ft_putendl(tmp->data->d_name);
		tmp = tmp->next;
	}
}
