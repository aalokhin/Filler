#include "filler.h"

void		print_coord(t_all *find)
{
		//write(find->fd, "coordinates_on_output\n", 21);
		ft_putnbr_fd(find->res_y, 1);
		write(1, " ", 1);
		ft_putnbr_fd(find->res_x, 1);
		write(1, "\n", 1);

		write(find->fd, "!", 1);
		ft_putnbr_fd(find->res_x, find->fd);
		write(find->fd, " ", 1);
		ft_putnbr_fd(find->res_y, find->fd);
		write(find->fd, "\n", 1);
}


// void		ft_print_struct(t_all *find)
// {
// 	// int i;

// 	// dprintf(find->fd, "\nme>>%c\n", find->me);
// 	// dprintf(find->fd, "enemy>>%c\n", find->enemy);
// 	// dprintf(find->fd, "width_map>>%d\n", find->map_w);
// 	// dprintf(find->fd, "height_map>>%d\n", find->map_h);
// 	// dprintf(find->fd, "width_chnk>>%d\n", find->chnk_w);
// 	// dprintf(find->fd, "height_chnk>>%d\n", find->chnk_h);
// 	// dprintf(find->fd, "return_x>>%d\n", find->res_x);
// 	// dprintf(find->fd, "return_y>>%d\n", find->res_y);
// 	// i = 0;
// 	// dprintf(find->fd, "map:\n");
// 	// while(i < find->map_h)
// 	// {
// 	// 	dprintf(find->fd, "%s\n", find->map[i]);
// 	// 	i++;
// 	// }
// 	// i = 0;
// 	// dprintf(find->fd, "piece iteration nbr %d:\n", find->costul);
// 	// while(find->chnk[i])
// 	// {
// 	// 	dprintf(find->fd, "%s\n", find->chnk[i]);
// 	// 	i++;
// 	// }

// 	// i = 0;
// 	// dprinf(2, "%s\n");
// 	// find->fd = find->fd;
// 	// while ()
// 	// dprintf(2, "\nme>>%c\n", find->me);
// 	// dprintf(2, "enemy>>%c\n", find->enemy);
// 	// dprintf(2, "width_map>>%d\n", find->map_w);
// 	// dprintf(2, "height_map>>%d\n", find->map_h);

// 	// dprintf(2, "return_x>>%d\n", find->res_x);
// 	// dprintf(2, "return_y>>%d\n", find->res_y);
// 	// i = 0;
// 	// dprintf(2, "map:\n");
// 	// while(i < find->map_h)
// 	// {
// 	// 	dprintf(2, "%s\n", find->map[i]);
// 	// 	i++;
// 	// }
// 	// i = 0;
// 	// dprintf(2, "piece iteration nbr %d:\n", find->costul);
// 	// while(find->chnk[i])
// 	// {
// 	// 	dprintf(2, "%s\n", find->chnk[i]);
// 	// 	i++;
// 	// }


	
// }

