/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 08:40:23 by efarhat           #+#    #+#             */
/*   Updated: 2023/02/09 12:52:19 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_path_valid(t_map *map)
{
	get_coord(map, 'P');
	count_comps(map);
	map->looted = 0;
	map->arr2d = get_map(map->file);
	if (!map->arr2d)
		return (0);
	map->height = num_lines_map(map->file);
	map->width = lenline(map->arr2d[0]);
	if (find_path(map, map->x, map->y) == 0)
	{
		ft_clear(map->arr2d);
		return (0);
	}
	ft_clear(map->arr2d);
	map->arr2d = get_map(map->file);
	if (!map->arr2d)
		return (0);
	if (path_collects(map) == 0)
	{
		ft_clear(map->arr2d);
		return (0);
	}
	ft_clear(map->arr2d);
	return (1);
}

void	get_coord(t_map *map, char c)
{
	int		i;
	int		j;

	i = 0;
	map->arr2d = get_map(map->file);
	if (!map->arr2d)
		return ;
	while (map->arr2d[i])
	{
		j = 0;
		while (map->arr2d[i][j])
		{
			if (map->arr2d[i][j] == c)
			{
				map->y = i;
				map->x = j;
				break ;
			}
			j++;
		}
		i++;
	}
	ft_clear(map->arr2d);
}

int	path_collects(t_map *map)
{
	int		i;
	int		j;

	j = 0;
	while (map->arr2d[j])
	{
		i = 0;
		while (map->arr2d[j][i])
		{
			if (map->arr2d[j][i] == 'C')
			{
				if (!find_path_collects(map, i, j))
					return (0);
				ft_clear(map->arr2d);
				map->arr2d = get_map(map->file);
				if (!map->arr2d)
					return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	find_path(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || y >= map->height || x >= map->width)
		return (0);
	else if (map->arr2d[y][x] == '1')
		return (0);
	else if (map->arr2d[y][x] == 'E')
		return (1);
	else
	{
		map->arr2d[y][x] = '1';
		if (find_path(map, x - 1, y)
			|| find_path(map, x + 1, y)
			|| find_path(map, x, y - 1)
			|| find_path(map, x, y + 1))
			return (1);
	}
	return (0);
}

int	find_path_collects(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || y >= map->height || x >= map->width)
		return (0);
	else if (map->arr2d[y][x] == '1' || map->arr2d[y][x] == 'E')
		return (0);
	else if (map->arr2d[y][x] == 'P')
		return (1);
	else
	{
		map->arr2d[y][x] = '1';
		if (find_path_collects(map, x - 1, y)
			|| find_path_collects(map, x + 1, y)
			|| find_path_collects(map, x, y - 1)
			|| find_path_collects(map, x, y + 1))
			return (1);
	}
	return (0);
}
