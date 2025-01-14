/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:40:04 by efarhat           #+#    #+#             */
/*   Updated: 2023/02/06 17:25:14 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_map(int fd)
{
	char		*s;
	char		*buff;
	int			rdd;

	if (fd == -1)
		return (0);
	rdd = 1;
	s = NULL;
	buff = malloc(sizeof(char) * 2);
	if (!buff)
		return (NULL);
	while (rdd > 0)
	{
		rdd = read(fd, buff, 1);
		if (rdd == -1)
		{
			if (s)
				free(s);
			return (free(buff), NULL);
		}
		buff[rdd] = '\0';
		s = ft_strjoin_gnl(s, buff);
	}
	free(buff);
	return (s);
}
