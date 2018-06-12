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

void			check_distance(t_oken *head, t_all *find)
{
	int			res;

	res = modul(head->x, find->x) + modul(head->y, find->y);
	if (find->dst == -1 || (find->dst != -1 && res < find->dst))
	{
		find->dst = res;
		find->res_x = head->x;
		find->res_y = head->y;
	}
}

void			ft_filler(t_all *find)
{
	t_oken		*head;

	find->y = 0;
	head = NULL;
	while (find->y < find->map_h)
	{
		find->x = 0;
		while (find->x < find->map_w)
		{
			if (check_placement(find) == 1)
			{
				if (head == NULL)
					head = create_list(find);
				else
					add(&head, find);
			}
			find->x++;
		}
		find->y++;
	}
	find_final(find, head);
	delete_list(&head);
	print_coord(find);
}
