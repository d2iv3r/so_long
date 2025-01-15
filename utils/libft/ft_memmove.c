/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:59:49 by efarhat           #+#    #+#             */
/*   Updated: 2022/11/08 11:48:04 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	if (src == NULL && dst == NULL)
	{
		return (NULL);
	}
	d = (char *)dst;
	s = (char *)src;
	i = len;
	if (src < dst)
	{
		while (i--)
		{
			d[i] = s[i];
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
