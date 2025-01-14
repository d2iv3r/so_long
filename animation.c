/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:07:52 by efarhat           #+#    #+#             */
/*   Updated: 2023/02/10 16:20:54 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initial_utils_anm(t_map *map)
{
	map->anm.anm1 = mlx_xpm_file_to_image(map->mlx_ptr, ANM1,
			&map->anm.wth, &map->anm.hght);
	map->anm.anm2 = mlx_xpm_file_to_image(map->mlx_ptr, ANM2,
			&map->anm.wth, &map->anm.hght);
	map->anm.anm3 = mlx_xpm_file_to_image(map->mlx_ptr, ANM3,
			&map->anm.wth, &map->anm.hght);
	map->anm.anm4 = mlx_xpm_file_to_image(map->mlx_ptr, ANM4,
			&map->anm.wth, &map->anm.hght);
	map->anm.anm5 = mlx_xpm_file_to_image(map->mlx_ptr, ANM5,
			&map->anm.wth, &map->anm.hght);
	map->anm.anm6 = mlx_xpm_file_to_image(map->mlx_ptr, ANM6,
			&map->anm.wth, &map->anm.hght);
	map->anm.anm7 = mlx_xpm_file_to_image(map->mlx_ptr, ANM7,
			&map->anm.wth, &map->anm.hght);
	map->anm.anm8 = mlx_xpm_file_to_image(map->mlx_ptr, ANM8,
			&map->anm.wth, &map->anm.hght);
	map->anm.anm9 = mlx_xpm_file_to_image(map->mlx_ptr, ANM9,
			&map->anm.wth, &map->anm.hght);
	map->anm.anm10 = mlx_xpm_file_to_image(map->mlx_ptr, ANM10,
			&map->anm.wth, &map->anm.hght);
	if (!(map->anm.anm1 || map->anm.anm2 || map->anm.anm3 || map->anm.anm4
			|| map->anm.anm5 || map->anm.anm6 || map->anm.anm7
			|| map->anm.anm8 || map->anm.anm9 || map->anm.anm10))
		return (0);
	return (1);
}

void	put_img2(t_map *map, int x, int y, int i)
{
	if (i == 500)
		put_img(map, x, y, map->anm.anm1);
	if (i == 1000)
		put_img(map, x, y, map->anm.anm2);
	if (i == 1500 || i == 5500 || i == 9500 || i == 13500 || i == 17500)
		put_img(map, x, y, map->anm.anm3);
	if (i == 2000 || i == 6000 || i == 10000 || i == 14000 || i == 18000)
		put_img(map, x, y, map->anm.anm4);
	if (i == 2500 || i == 6500 || i == 10500 || i == 14500 || i == 18500)
		put_img(map, x, y, map->anm.anm5);
	if (i == 3000 || i == 7000 || i == 11000 || i == 15000 || i == 19000)
		put_img(map, x, y, map->anm.anm6);
	if (i == 3500 || i == 7500 || i == 11500 || i == 15500 || i == 19500)
		put_img(map, x, y, map->anm.anm7);
	if (i == 4000 || i == 8000 || i == 12000 || i == 16000 || i == 20000)
		put_img(map, x, y, map->anm.anm8);
	if (i == 4500 || i == 8500 || i == 12500 || i == 16500 || i == 20500)
		put_img(map, x, y, map->anm.anm9);
	if (i == 5000 || i == 9000 || i == 13000 || i == 17000 || i == 21000)
	{
		put_img(map, x, y, map->empty);
		put_img(map, x, y, map->anm.anm10);
	}
}

void	ft_mlx_clear2(t_map *map)
{
	if (map->n > 0)
	{
		mlx_destroy_image(map->mlx_ptr, map->anm.anm1);
		mlx_destroy_image(map->mlx_ptr, map->anm.anm2);
		mlx_destroy_image(map->mlx_ptr, map->anm.anm3);
		mlx_destroy_image(map->mlx_ptr, map->anm.anm4);
		mlx_destroy_image(map->mlx_ptr, map->anm.anm5);
		mlx_destroy_image(map->mlx_ptr, map->anm.anm6);
		mlx_destroy_image(map->mlx_ptr, map->anm.anm7);
		mlx_destroy_image(map->mlx_ptr, map->anm.anm8);
		mlx_destroy_image(map->mlx_ptr, map->anm.anm9);
		mlx_destroy_image(map->mlx_ptr, map->anm.anm10);
	}
}

int	animation(t_map *map)
{
	static int	i;
	static int	j;

	if (i > 500 && i < 21500
		&& map->arr2d[map->anm.crd[j].y][map->anm.crd[j].x] == 'P')
	{
		ft_clear(map->arr2d);
		ft_mlx_clear(map, 2);
		ft_error("HAHAHAHA!! YOU LOSE", EXIT_FAILURE);
	}
	put_img2(map, map->anm.crd[j].x, map->anm.crd[j].y, i);
	if (i == 21500)
	{
		put_img(map, map->anm.crd[j].x, map->anm.crd[j].y, map->empty);
		if (map->anm.crd[j + 1].x != 0 && map->anm.crd[j + 1].y != 0)
			j++;
		else
			j = 0;
		i = 0;
	}
	i++;
	return (0);
}
