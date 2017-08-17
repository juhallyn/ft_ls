/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:49:56 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/17 18:52:29 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

t_path			*create_node(t_data *data)
{
	t_path	*new;

	new = (t_path*)malloc(sizeof(t_path));
	if (!new)
		exit(-1);
	new->data = data;
	new->next = NULL;
	return (new);
}

t_path			*add_head(t_path *list, t_data *data)
{
	t_path	*new;

	new = (t_path*)malloc(sizeof(t_path));
	if (!new)
		exit(-1);
	new->data = data;
	new->next = list;
	return (new);
}

t_path			*add_end(t_path *list, t_data *data)
{
	t_path *new;
	t_path *tmp;

	tmp = list;
	new = (t_path*)malloc(sizeof(t_path));
	if (!new)
		exit(-1);
	new->data = data;
	new->next = NULL;
	if (list == NULL)
		return (new);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}

void			special_print(t_path *list)
{
	if (list->data->min_maj == false)
	{
		ft_putentab(list->data->group);
		ft_putnbr(list->data->file_size);
	}
	else
		print_major_minor(list->data->device);
	ft_putchar('\t');
	ft_putentab(list->data->time);
	if (list->data->is_symlink == true)
		print_symlink(list->data->d_name, list->data->path);
	else
		ft_putendl(list->data->d_name);
}
