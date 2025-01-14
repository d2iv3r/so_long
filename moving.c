/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:53:11 by efarhat           #+#    #+#             */
/*   Updated: 2023/02/09 16:41:44 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	if (map->arr2d[map->y - 1][map->x] == '1')
		return ;
	else if (map->arr2d[map->y - 1][map->x] == 'E'
		&& map->looted != map->c)
		return ;
	else
	{
		map->arr2d[map->y][map->x] = '0';
		put_img(map, map->x, map->y, map->empty);
		map->y--;
		if (map->arr2d[map->y][map->x] == 'C')
			map->looted++;
		put_img(map, map->x, map->y, map->ply.up);
		if (map->arr2d[map->y][map->x] == 'E'
			&& map->looted == map->c)
		{
			ft_clear(map->arr2d);
			ft_mlx_clear(map, 2);
			ft_error("BRAVOOOO!! YOU WIN", EXIT_SUCCESS);
		}
		map->arr2d[map->y][map->x] = 'P';
	}
}

void	move_down(t_map *map)
{
	if (map->arr2d[map->y + 1][map->x] == '1')
		return ;
	else if (map->arr2d[map->y + 1][map->x] == 'E'
		&& map->looted != map->c)
		return ;
	else
	{
		map->arr2d[map->y][map->x] = '0';
		put_img(map, map->x, map->y, map->empty);
		map->y++;
		if (map->arr2d[map->y][map->x] == 'C')
			map->looted++;
		put_img(map, map->x, map->y, map->ply.down);
		if (map->arr2d[map->y][map->x] == 'E'
			&& map->looted == map->c)
		{
			ft_clear(map->arr2d);
			ft_mlx_clear(map, 2);
			ft_error("BRAVOOOO!! YOU WIN", EXIT_SUCCESS);
		}
		map->arr2d[map->y][map->x] = 'P';
	}
}

void	move_left(t_map *map)
{
	if (map->arr2d[map->y][map->x - 1] == '1')
		return ;
	else if (map->arr2d[map->y][map->x - 1] == 'E'
		&& map->looted != map->c)
		return ;
	else
	{
		map->arr2d[map->y][map->x] = '0';
		put_img(map, map->x, map->y, map->empty);
		map->x--;
		if (map->arr2d[map->y][map->x] == 'C')
			map->looted++;
		put_img(map, map->x, map->y, map->ply.left);
		if (map->arr2d[map->y][map->x] == 'E'
			&& map->looted == map->c)
		{
			ft_clear(map->arr2d);
			ft_mlx_clear(map, 2);
			ft_error("BRAVOOOO!! YOU WIN", EXIT_SUCCESS);
		}
		map->arr2d[map->y][map->x] = 'P';
	}
}

void	move_right(t_map *map)
{
	if (map->arr2d[map->y][map->x + 1] == '1')
		return ;
	else if (map->arr2d[map->y][map->x + 1] == 'E'
		&& map->looted != map->c)
		return ;
	else
	{
		map->arr2d[map->y][map->x] = '0';
		put_img(map, map->x, map->y, map->empty);
		map->x++;
		if (map->arr2d[map->y][map->x] == 'C')
			map->looted++;
		put_img(map, map->x, map->y, map->ply.right);
		if (map->arr2d[map->y][map->x] == 'E'
			&& map->looted == map->c)
		{
			ft_clear(map->arr2d);
			ft_mlx_clear(map, 2);
			ft_error("BRAVOOOO!! YOU WIN", EXIT_SUCCESS);
		}
		map->arr2d[map->y][map->x] = 'P';
	}
}
