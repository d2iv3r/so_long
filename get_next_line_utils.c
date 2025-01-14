/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:39:34 by efarhat           #+#    #+#             */
/*   Updated: 2023/02/06 17:25:43 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s, char *buff)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
	{
		s = (char *)malloc(1 * sizeof(char));
		if (!s)
			return (NULL);
		s[0] = '\0';
	}
	if (!buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen_gnl(s) + ft_strlen_gnl(buff)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i] != '\0')
		str[i] = s[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_gnl(s) + ft_strlen_gnl(buff)] = '\0';
	free(s);
	return (str);
}
