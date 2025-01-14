/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:32:19 by efarhat           #+#    #+#             */
/*   Updated: 2022/11/08 11:45:09 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	size_t			len;
	char			*p;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (i < len && ft_strchr(set, s1[i]))
		i++;
	while (len-- > i && ft_strchr(set, s1[len]))
		j++;
	size = ft_strlen(s1) - i - j;
	p = (char *)malloc(sizeof(char) * size + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1 + i, size * sizeof(char) + 1);
	return (p);
}
