/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:57:59 by efarhat           #+#    #+#             */
/*   Updated: 2022/11/25 14:04:23 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned long long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb > 0)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

int	ft_prthexa(unsigned long long n, int type)
{
	unsigned long long	nb;

	nb = n;
	if (n == 0)
		ft_prtchar(48);
	else if (n >= 16)
	{
		ft_prthexa(n / 16, type);
		ft_prthexa(n % 16, type);
	}
	else if (n >= 10 && n <= 15)
		ft_prtchar(n + type);
	else
		ft_prtchar(n + 48);
	return (ft_numlen(nb));
}
