/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:41:32 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/04 14:48:47 by juhallyn         ###   ########.fr       */
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
