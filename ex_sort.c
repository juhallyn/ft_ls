/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:46:22 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/23 19:50:00 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

void		time_ascci(t_path **list, t_path **tmp, t_path **new)
{
	if (ft_strcmp((*new)->data->d_name, (*tmp)->data->d_name) < 0)
	{
		*list = (*new);
		(*new)->next = *tmp;
	}
}

void		time_ascci_2(t_path *prev, t_path *tmp, t_path *new)
{
	if (ft_strcmp((new)->data->d_name, (tmp)->data->d_name) < 0)
	{
		(prev)->next = new;
		(new)->next = tmp;
	}
}
