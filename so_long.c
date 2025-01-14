/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:25:17 by efarhat           #+#    #+#             */
/*   Updated: 2023/02/10 16:21:28 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		ft_error("Error : Invalide arguments!", EXIT_FAILURE);
	else
	{
		map.file = argv[1];
		check_map(&map);
		if (is_path_valid(&map) == 0)
			ft_error("Error :\n Invalide path!", EXIT_FAILURE);
		if (!initial_utils_map(&map))
		{
			ft_clear(map.arr2d);
			ft_mlx_clear(&map, 1);
			ft_error("Error :\n Invalide map utils!", EXIT_FAILURE);
		}
		parse_map(&map);
		playing(&map);
	}
	return (0);
}
