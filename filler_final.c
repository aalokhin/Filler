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

void		find_final(t_all *find, t_oken *head)
{
	t_oken		*tmp;
	int			dst;

	if (head == NULL)
	{
		find->res_x = 0;
		find->res_y = 0;
		return ;
	}
	dst = head->dist;
	tmp = head;
	find->res_x = head->x;
	find->res_y = head->y;
	while (head != NULL)
	{
		if (head->dist < dst)
		{
			dst = head->dist;
			find->res_x = head->x;
			find->res_y = head->y;
		}
		head = head->next;
	}
	head = tmp;
}

void		print_coord(t_all *find)
{
	ft_putnbr_fd(find->res_y, 1);
	write(1, " ", 1);
	ft_putnbr_fd(find->res_x, 1);
	write(1, "\n", 1);
}
