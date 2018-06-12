/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:58:42 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/10 12:58:44 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			locate_enemy(t_all *find)
{
	if ((find->map[find->y][find->x] == find->enemy ||\
	find->map[find->y][find->x] == find->enemy + 32) ||\
	(find->y == 0 || find->y == find->map_h - 1 ||\
	find->x == 0 || find->y == find->map_w - 1))
		return (1);
	return (0);
}

void		find_final(t_all *find, t_oken *head)
{
	t_oken		*tmp;

	tmp = head;
	find->dst = -1;
	find->y = 0;
	while (find->y < find->map_h)
	{
		find->x = 0;
		while (find->x < find->map_w)
		{
			if (locate_enemy(find) == 1)
			{
				head = tmp;
				while (head != NULL)
				{
					check_distance(head, find);
					head = head->next;
				}
			}
			find->x++;
		}
		find->y++;
	}
}

void		ft_free_struct(t_all *find)
{
	int		i;

	i = 0;
	while(i < find->map_h)
	{
		ft_strdel(&find->map[i]);
		i++;
	}
	i = 0;
	while(i < find->chnk_h)
	{
		ft_strdel(&find->chnk[i]);
		i++;
	}
	ft_bzero(&find, sizeof(find));
}

void		print_coord(t_all *find)
{
	ft_putnbr_fd(find->res_y, 1);
	write(1, " ", 1);
	ft_putnbr_fd(find->res_x, 1);
	write(1, "\n", 1);
	ft_free_struct(find);
	
	//while(1);
}
