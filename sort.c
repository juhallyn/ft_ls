/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:25:35 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/04 13:36:26 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

void		chose_insert(t_path **list, t_path *new, t_ops ops)
{
	if (ops.t_option == true)
		insert_time(list, new);
	else
		insert_ascii(list, new);
}

void		insert_ascii(t_path **list, t_path *new)
{
	t_path		*tmp;
	t_path		*prev;

	tmp = *list;
	if (ft_strcmp(new->data->d_name, tmp->data->d_name) < 0)
	{
		*list = new;
		new->next = tmp;
		return ;
	}
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
		if (ft_strcmp(new->data->d_name, tmp->data->d_name) < 0)
		{
			prev->next = new;
			new->next = tmp;
			return ;
		}
	}
	tmp->next = new;
}

void		insert_time(t_path **list, t_path *new)
{
	t_path		*tmp;
	t_path		*prev;

	tmp = *list;
	if (new->data->modif_time > tmp->data->modif_time)
	{
		*list = new;
		new->next = tmp;
		return ;
	}
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
		if (new->data->modif_time > tmp->data->modif_time)
		{
			prev->next = new;
			new->next = tmp;
			return ;
		}
	}
	tmp->next = new;
}
