/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:49:56 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/03 16:41:37 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

t_path	*add_head(t_path *list, t_data *data)
{
	t_path *new;

	new = (t_path*)malloc(sizeof(t_path));
	if (new == NULL)
		perror("");
	new->data = data;
	new->next = NULL;
	return (new);
}

t_path	*create_node(t_data *data)
{
	t_path	*new;

	new = (t_path*)malloc(sizeof(t_path));
	if (!new)
		perror("");
	new->data = data;
	new->next = NULL;
	return (new);
}

t_path		*add_end(t_path *list, t_data *data)
{
	t_path *new;
	t_path *tmp;

	tmp = list;
	new = (t_path*)malloc(sizeof(t_path));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	if (list == NULL)
		return (new);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}

void	print_list(t_path *list)
{
	t_path	*tmp;
	short	block;

	block = 0;
	tmp = list;
	while (tmp)
	{
		if (block == 0)
			print_blocks(all_blocks(list));
		block = 1;
		ft_putentab(tmp->data->permission);
		ft_putnbr(tmp->data->hard_link);
		ft_putchar('\t');
		ft_putentab(tmp->data->owner);
		ft_putentab(tmp->data->group);
		ft_putnbr(tmp->data->file_size);
		ft_putchar('\t');
		ft_putentab(tmp->data->time);
		ft_putendl(tmp->data->d_name);
		tmp = tmp->next;
	}
}

void	print_test(t_path *list)
{
	t_path *tmp;

	tmp = list;
	while (tmp)
	{
		ft_putendl(tmp->data->d_name);
		tmp = tmp->next;
	}
}
