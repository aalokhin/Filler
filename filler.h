/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:58:57 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/10 12:58:59 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_all
{
	int				x;
	int				y;
	char			me;
	char			enemy;
	int				map_w;
	int				map_h;
	int				chnk_w;
	int				chnk_h;
	int				res_x;
	int				res_y;
	int				dst;
	char			**map;
	char			**chnk;
}					t_all;

typedef struct		s_oken
{
	int				x;
	int				y;
	int				dist;
	struct s_oken	*next;

}					t_oken;

typedef struct		s_chk
{
	int				x;
	int				y;
	int				a;
}					t_chk;

void				ft_free_struct(t_all *find);

int					fit_in(t_all *find);
int					locate_enemy(t_all *find);
int					verify(char c, t_all *find);
void				check_distance(t_oken *head, t_all *find);
int					modul(int a1, int a2);
void				find_final(t_all *find, t_oken *head);
t_oken				*create_list(t_all *find);
void				delete_list(t_oken **head);
void				add(t_oken **head, t_all *find);
void				find_me(t_all *find, char *line);
void				find_map_size(t_all *find, char *line);
void				print_coord(t_all *find);
void				find_chnk_size(t_all *find, char *line);
int					check_placement(t_all *find);
void				ft_filler(t_all *find);

#endif
