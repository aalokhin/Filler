 # include "filler.h"

t_oken		*create_list(t_all *find)
{
	t_oken 	*head;

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
	t_enem 	*head;

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

t_enem		*find_enemy(t_all *find)
{
	int			x;
	int			y;
	t_enem		*head;

	x = 0;
	y = 0;
	head = NULL;

	while(y < find->map_h)
	{
		x = 0;
		while(x < find->map_w)
		{
			
			if(find->map[y][x] == find->enemy + 32 || find->map[y][x] == find->enemy)
			{
				//write(find->fd, "enemy1", 6);
				if (head == NULL)
					head = enem_list(x, y);
				else
					enem_add(&head, x, y);
			}
			x++;
		}
		y++;
	}
	t_enem *tmp;
	tmp = head;
	while(head != NULL)
	{
		write(find->fd, "enemy ", 6);
		ft_putnbr_fd(head->x, find->fd);
		write(find->fd, " ", 1);
		ft_putnbr_fd(head->y, find->fd);
		write(find->fd, "\n", 1);
		
		head = head->next;
	}
	head = tmp;
	return(head);
}