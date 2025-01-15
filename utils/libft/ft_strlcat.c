/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:05:19 by efarhat           #+#    #+#             */
/*   Updated: 2022/11/08 11:44:37 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;
	size_t	l;

	if (!dst && dstsize == 0)
		return (0);
	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	l = dlen + slen;
	if (dstsize <= dlen || dstsize == 0)
	{
		return (dstsize + slen);
	}
	while (src[i] != '\0' && dlen < dstsize - 1)
	{
		dst[dlen] = src[i];
		i++;
		dlen++;
	}
	dst[dlen] = '\0';
	return (l);
}
