/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:32:24 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/10 12:32:27 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				verify(char c, t_all *find)
{
	if (c == find->enemy + 32 || c == find->enemy)
		return (1);
	if (c == find->me + 32 || c == find->me)
		return (2);
	return (0);
}

int				fit_in(t_all *find)
{
	if (!(find->x + find->chnk_w < find->map_w &&\
	find->y + find->chnk_h < find->map_h))
		return (1);
	return (0);
}

int				check_placement(t_all *find)
{
	t_chk		p;

	ft_bzero(&p, sizeof(p));
	if (fit_in(find) == 1)
		return (0);
	while (p.y < find->chnk_h)
	{
		p.x = 0;
		while (p.x < find->chnk_w)
		{
			if (find->chnk[p.y][p.x] == '*')
			{
				if (verify(find->map[p.y + find->y][p.x + find->x], find) == 1\
				|| p.a > 1)
					return (0);
				if (verify(find->map[p.y + find->y][p.x + find->x], find) == 2)
					p.a++;
			}
			p.x++;
		}
		p.y++;
	}
	if (p.a == 1)
		return (1);
	return (0);
}

t_enem			*find_enemy(t_all *find)
{
	t_chk		p;
	t_enem		*head;

	ft_bzero(&p, sizeof(p));
	head = NULL;
	while (p.y < find->map_h)
	{
		p.x = 0;
		while (p.x < find->map_w)
		{
			if (find->map[p.y][p.x] == find->enemy + 32 ||\
			find->map[p.y][p.x] == find->enemy)
			{
				if (head == NULL)
					head = enem_list(p.x, p.y);
				else
					enem_add(&head, p.x, p.y);
			}
			p.x++;
		}
		p.y++;
	}
	return (head);
}

void			ft_filler(t_all *find)
{
	t_oken		*head;
	t_enem		*enemy;

	find->y = 0;
	head = NULL;
	enemy = find_enemy(find);
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
	calculate_distance(enemy, &head);
	find_final(find, head);
	print_coord(find);
}
