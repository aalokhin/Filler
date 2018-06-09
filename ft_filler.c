 # include "filler.h"

int		check_placement(t_all *find)
{
	int i;
	int j;
	int	one;

	i = 0;
	one = 0;
	j = 0;

	
	if (!(find->x + find->chnk_w < find->map_w &&\
	find->y + find->chnk_h < find->map_h))
		return (0);
	while(j < find->chnk_h)
	{
		//write(find->fd, "here\n", 5);
		i = 0;
		while (i < find->chnk_w)
		{
			
			if(find->chnk[j][i] == '*')
			{
				//write(find->fd, "we met *\n", 9);
				if(find->map[j + find->y][i + find->x] == find->enemy + 32 ||\
				find->map[j + find->y][i + find->x] == find->enemy)
					return (0);
				if (find->map[j + find->y][i + find->x] == find->me + 32 ||\
				find->map[j + find->y][i + find->x] == find->me)
					one++;
			}
			if(one > 1)	
				return (0);
			i++;
		}
		j++;
	}
	if (one == 1)
		return (1);	
	return (0);
}


void		ft_filler(t_all *find)
{
	t_oken		*head;
	t_enem		*enemy;
	int a = 0;

	find->y = 0;
	find->x = 0;
	head = NULL;
	enemy = find_enemy(find);
	while(find->y < find->map_h)
	{
		find->x = 0;	
		while(find->x < find->map_w)
		{
			if (check_placement(find) == 1)
			{
				a++;
				 //we need to change this to the fundtion that adds these coordinates to the list  
				if (head == NULL)
					head = create_list(find);
				else
					add(&head, find);

			}
			find->x++;
		}
		find->y++;
	}
	calculate_distance(enemy, &head, find);
	find_final(find, head);
	// while(head != NULL)
	// {
	// 	find->res_x = head->x;
	// 	find->res_y = head->y;

	// 	// write(find->fd, "x y: ", 5);
	// 	// ft_putnbr_fd(head->y, find->fd);
	// 	// write(find->fd, ";", 1);
	// 	// ft_putnbr_fd(head->x, find->fd);
	// 	// write(find->fd, "\n", 1);
	// 	head = head->next;
	// }
	// write(find->fd, "\n", 1);
	// write(find->fd, " a is ", 5);
	// ft_putnbr_fd(a, find->fd);
	// write(find->fd, "\n", 1);

	print_coord(find);
}


	// write(find->fd, "#", 1);
	// ft_putnbr_fd(find->res_x, find->fd);
	// write(find->fd, " ", 1);
	// ft_putnbr_fd(find->res_y, find->fd);

	// write(find->fd, "create ", 7);
	// write(find->fd, "x y: ", 5);
	// ft_putnbr_fd(find->x, find->fd);
	// write(find->fd, ";", 1);
	// ft_putnbr_fd(find->y, find->fd);
	// write(find->fd, "\n", 1);

	// write(find->fd, "x y: ", 5);
	// ft_putnbr_fd(find->y, find->fd);
	// write(find->fd, ";", 1);
	// ft_putnbr_fd(find->x, find->fd);
	// write(find->fd, "\n", 1);

	// write(find->fd, "chunk ", 6);
	// ft_putnbr_fd(find->chnk_h, find->fd);
	// ft_putnbr_fd(find->chnk_w, find->fd);
	// write(find->fd, ";", 1);
	// write(find->fd, "\n", 1);
	// write(find->fd, "x y: ", 5);
				// ft_putnbr_fd(i, find->fd);
				// write(find->fd, ";", 1);
				// ft_putnbr_fd(j, find->fd);
				// write(find->fd, "\n", 1);
// write(find->fd, "enemy met ", 10);
					// ft_putnbr_fd(i + find->x, find->fd);
					// ft_putnbr_fd(j + find->y, find->fd);
					// write(find->fd, "\n", 1);
	// write(find->fd, "one plus", 8);
					// ft_putnbr_fd(i + find->x, find->fd);
					// ft_putnbr_fd(j + find->y, find->fd);
					// write(find->fd, "\n", 1);
//write(find->fd, "not valid\n", 10);
	// write(find->fd, "coordinate_found\n", 17);
		// ft_putnbr_fd(find->x, find->fd);
		// ft_putnbr_fd(find->y, find->fd);
//write(find->fd, "co_not_found\n", 13);
// write(find->fd, "x y: ", 5);
			// ft_putnbr_fd(find->y, find->fd);
			// write(find->fd, ";", 1);
			// ft_putnbr_fd(find->x, find->fd);
			// write(find->fd, "\n", 1);
// write(find->fd, "filler_found_now\n", 17);
				// ft_putnbr_fd(find->res_x, find->fd);
				// ft_putnbr_fd(find->res_y, find->fd);



		// write(find->fd, "I am addin\n", 11);
		// write(find->fd, "x y: ", 5);
		// ft_putnbr_fd(find->x, find->fd);
		// write(find->fd, ";", 1);
		// ft_putnbr_fd(find->y, find->fd);
		// write(find->fd, "\n", 1);
