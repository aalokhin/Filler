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
	t_oken		*last;

	new = create_list(find);
	if (!new || !head)
		return ;
	last = *head;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void		delete_list(t_oken *head)
{
	t_oken *next;

	if (!head)
		return ;
	while (head != NULL)
	{
		next = head->next;
		head->x = 0;
		head->y = 0;
		head->dist = 0;
		free(head);
		head = next;
	}
}
