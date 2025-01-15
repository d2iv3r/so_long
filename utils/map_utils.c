/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 09:57:00 by efarhat           #+#    #+#             */
/*   Updated: 2023/02/08 14:01:39 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lenline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	num_lines_map(char *file)
{
	t_map	map;
	int		i;

	map.arr2d = get_map(file);
	if (!map.arr2d)
		return (0);
	i = 0;
	while (map.arr2d[i])
		i++;
	ft_clear(map.arr2d);
	return (i);
}

int	count_comp_line(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	count_comps(t_map *map)
{
	int		i;

	map->arr2d = get_map(map->file);
	if (!map->arr2d)
		return ;
	map->f = 0;
	map->w = 0;
	map->c = 0;
	map->e = 0;
	map->p = 0;
	map->n = 0;
	i = 0;
	while (map->arr2d[i])
	{
		map->f += count_comp_line(map->arr2d[i], '0');
		map->w += count_comp_line(map->arr2d[i], '1');
		map->c += count_comp_line(map->arr2d[i], 'C');
		map->e += count_comp_line(map->arr2d[i], 'E');
		map->p += count_comp_line(map->arr2d[i], 'P');
		map->n += count_comp_line(map->arr2d[i], 'N');
		i++;
	}
	ft_clear(map->arr2d);
}

char	*get_height_line(char **str, int numlines, int j)
{
	int		i;
	char	*str_height;

	str_height = malloc(sizeof(char) * (numlines + 1));
	if (!str_height)
		return (0);
	i = 0;
	while (i <= numlines)
	{
		str_height[i] = str[i][j];
		i++;
	}
	str_height[i] = '\0';
	return (str_height);
}
