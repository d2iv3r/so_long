/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtuni.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:26:11 by efarhat           #+#    #+#             */
/*   Updated: 2022/11/25 18:58:56 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	ft_prtuni(unsigned int n)
{
	unsigned int	nb;

	nb = n;
	if (n == 0)
		ft_prtchar(48);
	else if (n >= 10)
	{
		ft_prtuni(n / 10);
		ft_prtuni(n % 10);
	}
	else
		ft_prtchar(n + 48);
	return (ft_numlen(nb));
}
