 # include "filler.h"

int		modul(int a1, int a2)
{
	int			ret;

	ret = 0;
	if((a1 - a2) >= 0)
		ret = a1 - a2;
	else
		ret = (a1 - a2) * (-1);
	return (ret);

}

int			manhattan_dist_min(int x, int y, t_enem *enemy, t_all *find) //find tpprint to fd only
{
	int 		min;
	int			tmp;
	t_enem 		*node;

	node = enemy;
	tmp = modul(x, enemy->x) + modul(y, enemy->y);
	min = tmp;
	int a = 0;
	// if (node->next)
	// 	node = node->next;
	find->fd = find->fd;
	while(node != NULL)
	{
		tmp = modul(x, enemy->x) + modul(y, enemy->y);
		min = (tmp <= min) ? tmp : min; 

		// write(find->fd, "manhattan_lookup ", 17);
		// ft_putnbr_fd(tmp, find->fd);
		// write(find->fd, "\n", 1);

		a++;

		node = node->next;
	}
	// write(find->fd, "minimum ", 8);
	// ft_putnbr_fd(min, find->fd);
	// write(find->fd, "\n", 1);
	// write(find->fd, "a is  ", 5);
	// ft_putnbr_fd(a, find->fd);
	// write(find->fd, "\n", 1);
	return(min);
}

void		calculate_distance(t_enem *enemy, t_oken **head, t_all *find)
{
	t_oken		*tmp;
	
	tmp = (*head);
	while((*head) != NULL)
	{
		(*head)->dist = manhattan_dist_min((*head)->x, (*head)->y, enemy, find);
		(*head) = (*head)->next;
	}
	*head = tmp;
}

void		find_final(t_all *find, t_oken *head)
{
	t_oken		*tmp;
	int			dst;

	write(find->fd, "find final\n", 11);
	
	if (head == NULL)
	{
		write(find->fd, "here?\n", 6);
		find->res_x = 0;
		find->res_y = 0;
		return ;
	}
	dst = head->dist;
	tmp = head;
	find->res_x = head->x;
	find->res_y = head->y;
	while(head != NULL)
	{
		write(find->fd, "iterating...\n", 13);
		ft_putnbr_fd(head->dist, find->fd);
		write(find->fd, "\n", 1);
		if (head->dist < dst)
		{
			write(find->fd, "what do we have here\n", 21);
			dst = head->dist;
			find->res_x = head->x;
			find->res_y = head->y;
		}
		head = head->next;
	}
	head = tmp;
}
