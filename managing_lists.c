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

void		delete_list(t_oken **head)
{
	t_oken *cur;
	t_oken *next;
	int fd = open("ftest", O_RDWR);

	if(!head)
		return ;
	cur = *head;
	while (cur != NULL)
	{
		 	write(fd, "free x y\n", 9);
			ft_putnbr_fd(cur->x, fd);
			write(fd, " ", 1);
			ft_putnbr_fd(cur->y, fd);
			write(fd, "\n", 1);

		next = cur->next;
		cur->x = 0;
		cur->y = 0;
		cur->dist = 0;
		free(cur);
		cur = next;
	}
	*head = NULL;
}