 # include "filler.h"

void			find_map_size(t_all *find, char *line)
{
	int			i;

	i = 0;
	while(!ft_isdigit(line[i]))
		i++;
	find->map_h = ft_atoi(&line[i]);
	find->map_w = ft_atoi(&line[i + 2]);
	i = 0;
	get_next_line(0, &line);
	find->map = (char**)malloc(sizeof(char*) * (find->map_h + 1));
	while(i < find->map_h)
	{
		get_next_line(0, &line);
		find->map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	find->map[i] = NULL;
	get_next_line(0, &line);
	if (line && !ft_strncmp(line, "Piece ", 6))
		find_chnk_size(find, line);
	ft_filler(find); //start doing filler
}

void			find_chnk_size(t_all *find, char *line)
{
	int			i;

	i = 0;
	//ft_putstr_fd(line, find->fd);
	while(!ft_isdigit(line[i]))
		i++;
	find->chnk_h = ft_atoi(&line[i]);
	find->chnk_w = ft_atoi(&line[i + 2]);

	i = 0;
	find->chnk = (char**)malloc(sizeof(char*) * (find->chnk_h + 1));
	while(i < find->chnk_h)
	{
		get_next_line(0, &line);
		find->chnk[i] = ft_strdup(line);
		ft_putstr_fd(line, find->fd);
		write(find->fd, "\n", 1);
		ft_strdel(&line);
		i++;
	}
	find->chnk[i] = NULL;
	// write(find->fd, ">", 1);
	// ft_putnbr_fd(find->chnk_w, find->fd);
	// write(find->fd, " ", 1);
	// ft_putnbr_fd(find->chnk_h, find->fd);
	// write(find->fd, "\n", 1);
}

void			find_me(t_all *find, char *line)
{
	if(line[10] == '1')
	{
		find->me = 'O';
		find->enemy = 'X';
	}
	else
	{
		find->me = 'X';
		find->enemy = 'O';
	}
}

int			main(void)
{
	char		*line;
	t_all		find;


	line = NULL;
	ft_bzero(&find, sizeof(find));
	find.fd = open("ftest", O_RDWR);
	while (get_next_line(0, &line) > 0)
	{
		if(line && !ft_strncmp(line, "$$$ exec p", 10))
			find_me(&find, line);
		if (line && !ft_strncmp(line, "Plateau ", 8))
			find_map_size(&find, line);
		ft_strdel(&line);
	}
	//ft_print_struct(&find);
	return (0);
}

// write(find->fd, ">", 1);
// 	ft_putnbr_fd(find->chnk_w, find->fd);
// 	write(find->fd, " ", 1);
// 	ft_putnbr_fd(find->chnk_h, find->fd);
// 	write(find->fd, "\n", 1);


// ft_putstr_fd(line, find->fd);
// write(find->fd, "\n", 1);

	//ft_putstr_fd(line, find.fd);
		//write(find.fd, "\n", 1);
		// write(find.fd, "b\n", 2);