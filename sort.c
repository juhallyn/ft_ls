/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:25:35 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/26 09:16:08 by juhallyn         ###   ########.fr       */
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

int			insert_ascii(t_path **list, t_path *new)
{
	t_path	*temp;
	t_path	*old;

	temp = *list;
	if (ft_strcmp(new->data->d_name, temp->data->d_name) <= 0)
		return (add_head_node(list, &new));
	while (temp->next)
	{
		old = temp;
		temp = temp->next;
		if (ft_strcmp(new->data->d_name, temp->data->d_name) <= 0)
			return (add_middle_node(&old, &new, temp));
	}
	temp->next = new;
	return (0);
}

int			insert_time(t_path **list, t_path *new)
{
	t_path	*temp;
	t_path	*old;

	temp = *list;
	if (new->data->modif_time > temp->data->modif_time)
		return (add_head_node(list, &new));
	if (new->data->modif_time == temp->data->modif_time)
		if (ft_strcmp(new->data->d_name, temp->data->d_name) < 0)
			return (add_head_node(list, &new));
	while (temp->next)
	{
		old = temp;
		temp = temp->next;
		if (new->data->modif_time > temp->data->modif_time)
			return (add_middle_node(&old, &new, temp));
		if (new->data->modif_time == temp->data->modif_time)
			if (ft_strcmp(new->data->d_name, temp->data->d_name) < 0)
				return (add_middle_node(&old, &new, temp));
	}
	temp->next = new;
	return (0);
}

void		chose_insert(t_path **list, t_path *new, t_ops ops)
{
	if (ops.r_option == true && ops.t_option == true)
		insert_rev_time(list, new);
	else if (ops.t_option == true)
		insert_time(list, new);
	else if (ops.r_option == true)
		insert_rev_ascii(list, new);
	else
		insert_ascii(list, new);
}
