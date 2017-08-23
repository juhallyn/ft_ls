/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_exeptions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:22:53 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/23 15:01:21 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

void		time_sort_exception(t_path *tmp, t_path *new, t_path *prev)
{
	ft_putendl(tmp->data->d_name);
	if (ft_strcmp(new->data->d_name, tmp->data->d_name) < 0)
	{
		prev->next = new;
		new->next = tmp;
		return ;
	}
}
