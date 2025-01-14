/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:16:13 by efarhat           #+#    #+#             */
/*   Updated: 2022/11/26 11:28:49 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(long nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		i++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	ft_prtnbr(int nb)
{
	int	n;

	n = nb;
	if (nb == -2147483648)
	{
		ft_prtchar('-');
		ft_prtnbr(2);
		ft_prtnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_prtchar('-');
		ft_prtnbr(-nb);
	}
	else if (nb >= 10)
	{
		ft_prtnbr(nb / 10);
		ft_prtnbr(nb % 10);
	}
	else
		ft_prtchar(nb + 48);
	return (ft_numlen(n));
}
