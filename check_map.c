/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:34:20 by efarhat           #+#    #+#             */
/*   Updated: 2023/02/09 17:51:29 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_map *map)
{
	if (!check_map_ext(map->file))
		ft_error("Error :\n Invalide extension of map! (.ber)", EXIT_FAILURE);
	if (open(map->file, O_RDONLY) == -1)
		ft_error("Error :\n Invalide file!", EXIT_FAILURE);
	if (!is_map_rectangular(map))
		ft_error("Error :\n The map is not rectangular!", EXIT_FAILURE);
	count_comps(map);
	if (!(map->w > 0 && map->c > 0 && map->e == 1 && map->p == 1))
		ft_error("Error :\n Invalide components in the map!", EXIT_FAILURE);
	if (is_map_closed(map) != 0)
		ft_error("Error :\n The map not closed by walls!", EXIT_FAILURE);
}

int	check_map_ext(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!ext)
		return (0);
	if (ft_strncmp(ext, ".ber", 3) != 0)
		return (0);
	return (1);
}

char	**get_map(char *file)
{
	t_map	map;
	char	*s;
	char	**arr2d;

	map.fd = open(file, O_RDONLY);
	if (map.fd == -1)
		return (0);
	s = ft_read_map(map.fd);
	arr2d = ft_split(s, '\n');
	if (!arr2d)
		return (NULL);
	free(s);
	close(map.fd);
	return (arr2d);
}

int	is_map_rectangular(t_map *map)
{
	int		len;

	map->arr2d = get_map(map->file);
	if (!map->arr2d)
		return (0);
	map->height = num_lines_map(map->file);
	map->width = lenline(map->arr2d[0]);
	if (map->width == map->height)
	{
		ft_clear(map->arr2d);
		return (0);
	}
	map->x = 0;
	while (map->x < map->height)
	{
		len = lenline(map->arr2d[map->x]);
		if (len != map->width)
		{
			ft_clear(map->arr2d);
			return (0);
		}
		map->x++;
	}
	ft_clear(map->arr2d);
	return (1);
}

int	is_map_closed(t_map *map)
{
	int		i;
	int		len;

	map->arr2d = get_map(map->file);
	if (!map->arr2d)
		return (0);
	map->height = num_lines_map(map->file) - 1;
	map->width = lenline(map->arr2d[0]);
	map->line_a = get_height_line(map->arr2d, map->height, 0);
	map->line_b = get_height_line(map->arr2d, map->height, map->width - 1);
	i = 0;
	if (map->width != count_comp_line(map->arr2d[0], '1'))
		i++;
	if (map->width != count_comp_line(map->arr2d[map->height], '1'))
		i++;
	len = lenline(map->line_a);
	if (len != count_comp_line(map->line_a, '1'))
		i++;
	len = lenline(map->line_b);
	if (len != count_comp_line(map->line_b, '1'))
		i++;
	free(map->line_a);
	free(map->line_b);
	ft_clear(map->arr2d);
	return (i);
}
