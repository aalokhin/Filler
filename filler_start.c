/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:25:13 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/10 12:25:15 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			find_map_size(t_all *find, char *line)
{
	int			i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	find->map_h = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	find->map_w = ft_atoi(&line[i]);
	i = 0;
	get_next_line(0, &line);
	find->map = (char**)malloc(sizeof(char*) * (find->map_h + 1));
	while (i < find->map_h)
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
}

void			find_chnk_size(t_all *find, char *line)
{
	int			i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	find->chnk_h = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	find->chnk_w = ft_atoi(&line[i]);
	i = 0;
	find->chnk = (char**)malloc(sizeof(char*) * (find->chnk_h + 1));
	while (i < find->chnk_h)
	{
		get_next_line(0, &line);
		find->chnk[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	find->chnk[i] = NULL;
	ft_filler(find);
}

void			find_me(t_all *find, char *line)
{
	if (line[10] == '1')
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

int				main(void)
{
	char		*line;
	t_all		find;

	line = NULL;
	ft_bzero(&find, sizeof(find));
	while (get_next_line(0, &line) > 0 && line)
	{
		if (line && !ft_strncmp(line, "$$$ exec p", 10))
			find_me(&find, line);
		if (line && !ft_strncmp(line, "Plateau ", 8))
			find_map_size(&find, line);
		ft_strdel(&line);
	}
	return (0);
}
