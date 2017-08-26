/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:31:24 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/26 08:52:55 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_ls.h"

static int	add_head_node(t_path **list, t_path **new)
{
	t_path	*temp;

	temp = *list;
	*list = *new;
	(*list)->next = temp;
	return (0);
}

static int	add_middle_node(t_path **old, t_path **new, t_path *temp)
{
	(*old)->next = *new;
	(*old)->next->next = temp;
	return (0);
}

int			insert_rev_ascii(t_path **list, t_path *new)
{
	t_path	*temp;
	t_path	*old;

	temp = *list;
	if (ft_strcmp(new->data->d_name, temp->data->d_name) >= 0)
		return (add_head_node(list, &new));
	while (temp->next)
	{
		old = temp;
		temp = temp->next;
		if (ft_strcmp(new->data->d_name, temp->data->d_name) >= 0)
			return (add_middle_node(&old, &new, temp));
	}
	temp->next = new;
	return (0);
}

int			insert_rev_time(t_path **list, t_path *new)
{
	t_path	*temp;
	t_path	*old;

	temp = *list;
	if (new->data->modif_time < temp->data->modif_time)
		return (add_head_node(list, &new));
	if (new->data->modif_time == temp->data->modif_time)
		if (ft_strcmp(new->data->d_name, temp->data->d_name) > 0)
			return (add_head_node(list, &new));
	while (temp->next)
	{
		old = temp;
		temp = temp->next;
		if (new->data->modif_time < temp->data->modif_time)
			return (add_middle_node(&old, &new, temp));
		if (new->data->modif_time == temp->data->modif_time)
			if (ft_strcmp(new->data->d_name, temp->data->d_name) > 0)
				return (add_middle_node(&old, &new, temp));
	}
	temp->next = new;
	return (0);
}
