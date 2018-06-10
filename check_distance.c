/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:58:57 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/10 12:58:59 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				modul(int a1, int a2)
{
	int			ret;

	ret = 0;
	if ((a1 - a2) >= 0)
		ret = a1 - a2;
	else
		ret = (a1 - a2) * (-1);
	return (ret);
}

int				manhattan_dist_min(int x, int y, t_enem *enemy)
{
	int			min;
	int			tmp;
	t_enem		*node;

	node = enemy;
	tmp = modul(x, enemy->x) + modul(y, enemy->y);
	min = tmp;
	while (node != NULL)
	{
		tmp = modul(x, enemy->x) + modul(y, enemy->y);
		min = (tmp < min) ? tmp : min;
		node = node->next;
	}
	return (min);
}

void			calculate_distance(t_enem *enemy, t_oken **head)
{
	t_oken		*tmp;

	tmp = (*head);
	while ((*head) != NULL)
	{
		(*head)->dist = manhattan_dist_min((*head)->x, (*head)->y, enemy);
		(*head) = (*head)->next;
	}
	*head = tmp;
}
