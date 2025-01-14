/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:48:51 by efarhat           #+#    #+#             */
/*   Updated: 2023/02/10 16:26:00 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>

// Textures
# define SIZE 64
# define WALL "textures/wall.xpm"
# define EMPTY "textures/empty.xpm"
# define AVATAR "textures/down.xpm"
# define DOWN "textures/down.xpm"
# define UP "textures/up.xpm"
# define RIGHT "textures/right.xpm"
# define LEFT "textures/left.xpm"
# define EXIT "textures/exit.xpm"
# define COLLECT "textures/collect.xpm"

//Animations
# define ANM1 "textures/anm/anm1.xpm"
# define ANM2 "textures/anm/anm2.xpm"
# define ANM3 "textures/anm/anm3.xpm"
# define ANM4 "textures/anm/anm4.xpm"
# define ANM5 "textures/anm/anm5.xpm"
# define ANM6 "textures/anm/anm6.xpm"
# define ANM7 "textures/anm/anm7.xpm"
# define ANM8 "textures/anm/anm8.xpm"
# define ANM9 "textures/anm/anm9.xpm"
# define ANM10 "textures/anm/anm10.xpm"

typedef struct s_player
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
}		t_p;

typedef struct s_crd
{
	int	x;
	int	y;
}		t_crd;

typedef struct s_anm
{
	int		hght;
	int		wth;
	t_crd	*crd;
	void	*anm1;
	void	*anm2;
	void	*anm3;
	void	*anm4;
	void	*anm5;
	void	*anm6;
	void	*anm7;
	void	*anm8;
	void	*anm9;
	void	*anm10;
}		t_anm;

typedef struct s_map
{
	char	*file;
	int		fd;
	int		height;
	int		width;
	char	**arr2d;
	int		w;
	int		f;
	int		c;
	int		e;
	int		p;
	int		n;
	int		looted;
	char	*line_a;
	char	*line_b;
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win;
	int		img_width;
	int		img_height;
	void	*wall;
	void	*empty;
	void	*collect;
	void	*avatar;
	void	*exitt;
	t_p		ply;
	t_anm	anm;
}		t_map;

// GET NEXT LINE
int		ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *s, char *buff);
char	*ft_read_map(int fd);

// ERROR
void	ft_error(char *msg, int ext);
void	ft_clear(char **str);
void	ft_mlx_clear(t_map *map, int i);
void	ft_mlx_clear2(t_map *map);

// MAP UTILS
int		lenline(char *s);
int		num_lines_map(char *file);
int		count_comp_line(char *str, char c);
void	count_comps(t_map *map);
char	*get_height_line(char **str, int numlines, int j);

// CHECKING THE MAP
void	check_map(t_map *map);
int		check_map_ext(char *file);
char	**get_map(char *file);
int		is_map_rectangular(t_map *map);
int		is_map_closed(t_map *map);

// CHECKING IF THERE IS A VALID PATH
int		is_path_valid(t_map *map);
void	get_coord(t_map *map, char c);
int		find_path(t_map *map, int x, int y);

// CHECKING IF THERE IS A VALID PATH TO EVERY COLLECTIBLE
int		path_collects(t_map *map);
int		find_path_collects(t_map *map, int x, int y);

// MAP PARSING
int		initial_utils_map(t_map *map);
void	put_img(t_map *map, int x, int y, void *img);
void	parse_map(t_map *map);

// PLAYING
int		initial_utils_ply(t_map *map);
void	playing(t_map *map);
int		handle_key(int key, t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);

// ANIMATION
int		initial_utils_anm(t_map *map);
int		animation(t_map *map);
void	get_coord_anm(t_map *map, char c);

#endif