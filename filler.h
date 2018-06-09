
#ifndef FILLER_H
# define FILLER_H

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_piece
{
	

	
}					t_piece;

typedef struct		s_all
{
	int				times_entered; //delete this before submission
	t_list			*tchk;
	int				fd;
	int				x; //coordinates to be checked then go to list in res_x and res_y
	int				y;
	char			me;
	char			enemy;

	int				map_w;
	int				map_h;
	int				chnk_w;
	int				chnk_h;
	int				res_x;
	int				res_y;
	char			**map;
	char			**chnk;
	int				end;//breaking while for gnl
	int				costul;
}					t_all;



typedef struct		s_oken
{
	int				x;
	int				y;
	int				dist;
	struct s_oken	*next;

}					t_oken;


typedef struct		s_enem
{
	int				x;
	int				y;
	struct s_enem	*next;

}					t_enem;

void		calculate_distance(t_enem *enemy, t_oken **head, t_all *find);

void		find_final(t_all *find, t_oken *head);

t_oken		*sort_l(t_oken *lst, int (*cmp)(int, int));

t_enem*		find_enemy(t_all *find);
t_enem		*enem_list(int x, int y);
void		enem_add(t_enem **head, int x, int y);


t_oken		*create_list(t_all *find);

void		add(t_oken **head, t_all *find);


void		find_me(t_all *find, char *line);
void		ft_print_struct(t_all *find);
void		find_map_size(t_all *find, char *line);
void		print_coord(t_all *find);
void		find_chnk_size(t_all *find, char *line);

int			check_placement(t_all *find);
void		ft_filler(t_all *find);

//void		ft_print_struct(t_all *find);


#endif