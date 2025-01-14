/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:16:04 by efarhat           #+#    #+#             */
/*   Updated: 2023/02/10 16:20:39 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initial_utils_map(t_map *map)
{
	map->arr2d = get_map(map->file);
	if (!map->arr2d)
		return (0);
	map->width = lenline(map->arr2d[0]) * SIZE;
	map->height = num_lines_map(map->file) * SIZE;
	map->mlx_ptr = mlx_init();
	map->win = mlx_new_window(map->mlx_ptr, map->width, map->height, "so_long");
	if (!map->win)
		return (0);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr, WALL,
			&map->img_width, &map->img_height);
	map->empty = mlx_xpm_file_to_image(map->mlx_ptr, EMPTY,
			&map->img_width, &map->img_height);
	map->avatar = mlx_xpm_file_to_image(map->mlx_ptr, AVATAR,
			&map->img_width, &map->img_height);
	map->exitt = mlx_xpm_file_to_image(map->mlx_ptr, EXIT,
			&map->img_width, &map->img_height);
	map->collect = mlx_xpm_file_to_image(map->mlx_ptr, COLLECT,
			&map->img_width, &map->img_height);
	if (map->width > 3200 || map->height > 1755)
		return (0);
	if (!(map->wall || map->empty || map->avatar || map->exitt || map->collect))
		return (0);
	return (1);
}

void	put_img(t_map *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win,
		img, x * SIZE, y * SIZE);
}

void	ft_mlx_clear(t_map *map, int i)
{
	if (i == 1)
	{
		mlx_destroy_image(map->mlx_ptr, map->wall);
		mlx_destroy_image(map->mlx_ptr, map->empty);
		mlx_destroy_image(map->mlx_ptr, map->avatar);
		mlx_destroy_image(map->mlx_ptr, map->exitt);
		mlx_destroy_image(map->mlx_ptr, map->collect);
		mlx_destroy_window(map->mlx_ptr, map->win);
	}
	if (i == 2)
	{
		mlx_destroy_image(map->mlx_ptr, map->wall);
		mlx_destroy_image(map->mlx_ptr, map->empty);
		mlx_destroy_image(map->mlx_ptr, map->avatar);
		mlx_destroy_image(map->mlx_ptr, map->exitt);
		mlx_destroy_image(map->mlx_ptr, map->collect);
		mlx_destroy_image(map->mlx_ptr, map->ply.up);
		mlx_destroy_image(map->mlx_ptr, map->ply.down);
		mlx_destroy_image(map->mlx_ptr, map->ply.left);
		mlx_destroy_image(map->mlx_ptr, map->ply.right);
		mlx_destroy_window(map->mlx_ptr, map->win);
	}
	ft_mlx_clear2(map);
}

void	parse_map(t_map *map)
{
	map->y = 0;
	while (map->arr2d[map->y])
	{
		map->x = 0;
		while (map->arr2d[map->y][map->x])
		{
			if (map->arr2d[map->y][map->x] != '1')
				put_img(map, map->x, map->y, map->empty);
			if (map->arr2d[map->y][map->x] == '1')
				put_img(map, map->x, map->y, map->wall);
			if (map->arr2d[map->y][map->x] == 'P')
				put_img(map, map->x, map->y, map->avatar);
			if (map->arr2d[map->y][map->x] == 'E')
				put_img(map, map->x, map->y, map->exitt);
			if (map->arr2d[map->y][map->x] == 'C')
				put_img(map, map->x, map->y, map->collect);
			map->x++;
		}
		map->y++;
	}
	ft_clear(map->arr2d);
}
