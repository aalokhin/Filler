/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managing_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:24:23 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/10 12:24:26 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_oken		*create_list(t_all *find)
{
	t_oken	*head;

	if (!(head = (t_oken*)malloc(sizeof(t_oken))))
		return (NULL);
	else
	{
		head->x = find->x;
		head->y = find->y;
		head->dist = 0;
	}
	head->next = NULL;
	return (head);
}

void		add(t_oken **head, t_all *find)
{
	t_oken		*new;

	new = create_list(find);
	if (!new || !head)
		return ;
	new->next = *head;
	*head = new;
}

t_enem		*enem_list(int x, int y)
{
	t_enem	*head;

	if (!(head = (t_enem*)malloc(sizeof(t_enem))))
		return (NULL);
	else
	{
		head->x = x;
		head->y = y;
	}
	head->next = NULL;
	return (head);
}

void		enem_add(t_enem **head, int x, int y)
{
	t_enem		*new;

	new = enem_list(x, y);
	if (!new || !head)
		return ;
	new->next = *head;
	*head = new;
}
