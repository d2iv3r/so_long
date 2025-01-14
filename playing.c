/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:30:58 by efarhat           #+#    #+#             */
/*   Updated: 2023/02/10 16:24:44 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initial_utils_ply(t_map *map)
{
	count_comps(map);
	get_coord(map, 'P');
	map->arr2d = get_map(map->file);
	if (!map->arr2d)
		return (0);
	map->looted = 0;
	map->ply.down = mlx_xpm_file_to_image(map->mlx_ptr,
			DOWN, &map->width, &map->height);
	map->ply.up = mlx_xpm_file_to_image(map->mlx_ptr,
			UP, &map->width, &map->height);
	map->ply.left = mlx_xpm_file_to_image(map->mlx_ptr,
			LEFT, &map->width, &map->height);
	map->ply.right = mlx_xpm_file_to_image(map->mlx_ptr,
			RIGHT, &map->width, &map->height);
	if (!(map->ply.down || map->ply.up || map->ply.left || map->ply.right))
		return (0);
	return (1);
}

int	handle_key(int key, t_map *map)
{
	static int	count;

	if (key == 126 || key == 125 || key == 124 || key == 123)
	{
		count++;
		ft_printf("%d\n", count);
		put_img(map, 0, 0, map->wall);
		mlx_string_put(map->mlx_ptr, map->win, SIZE / 3, SIZE / 2, 0,
			ft_itoa(count));
	}
	if (key == 53)
	{
		ft_clear(map->arr2d);
		ft_mlx_clear(map, 2);
		ft_error("good by", EXIT_SUCCESS);
	}
	if (key == 126)
		move_up(map);
	if (key == 125)
		move_down(map);
	if (key == 123)
		move_left(map);
	if (key == 124)
		move_right(map);
	return (0);
}

void	get_coord_anm(t_map *map, char c)
{
	t_crd	i;
	int		k;

	i.y = 0;
	k = 0;
	map->anm.crd = malloc(sizeof(t_crd) * (map->n + 1));
	if (!map->anm.crd)
		return ;
	while (map->arr2d[i.y])
	{
		i.x = 0;
		while (map->arr2d[i.y][i.x])
		{
			if (map->arr2d[i.y][i.x] == c)
			{
				map->anm.crd[k].x = i.x;
				map->anm.crd[k].y = i.y;
				k++;
			}
			i.x++;
		}
		i.y++;
	}
	map->anm.crd[k].x = 0;
	map->anm.crd[k].y = 0;
}

int	cross_click(t_map *map)
{
	ft_clear(map->arr2d);
	ft_mlx_clear(map, 2);
	ft_error("good by\n", EXIT_SUCCESS);
	return (0);
}

void	playing(t_map *map)
{
	if (!initial_utils_ply(map))
	{
		ft_clear(map->arr2d);
		ft_mlx_clear(map, 2);
		ft_error("Error :\n Invalide play utils!", EXIT_FAILURE);
	}
	mlx_hook(map->win, 17, 0L, &cross_click, map);
	mlx_key_hook(map->win, &handle_key, map);
	if (map->n > 0)
	{
		if (!initial_utils_anm(map))
		{
			ft_clear(map->arr2d);
			ft_mlx_clear(map, 2);
			ft_error("Error :\n Invalide play utils!", EXIT_FAILURE);
		}
		get_coord_anm(map, 'N');
		mlx_loop_hook(map->mlx_ptr, &animation, map);
	}
	mlx_loop(map->mlx_ptr);
}
