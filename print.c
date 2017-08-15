/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 19:37:58 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/15 20:22:10 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

void	print_list_reverse(t_path *list, t_path *tmp, bool total, t_ops ops)
{
	bool	block;

	block = true;
	if (!tmp)
		return ;
	if (block == true && total == true)
		print_blocks(all_blocks(list));
	print_list_reverse(list, tmp->next, total, ops);
	block = false;
	ft_putentab(tmp->data->permission);
	ft_putnbr(tmp->data->hard_link);
	ft_putchar('\t');
	ft_putentab(tmp->data->owner);
	special_print(tmp);
}

void	simple_print_reverse(t_path *list, t_ops ops)
{
	if (ops.r_option == true)
	{
		if (!list)
			return ;
		simple_print_reverse(list->next, ops);
		ft_putendl(list->data->d_name);
	}
	else
	{
		while (list)
		{
			ft_putendl(list->data->d_name);
			list = list->next;
		}
	}
}
