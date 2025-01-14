/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:15:28 by efarhat           #+#    #+#             */
/*   Updated: 2022/11/25 11:06:41 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prtstr(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
	{
		ft_prtstr("(null)");
		return (6);
	}	
	while (str[i] != '\0')
	{
		len += ft_prtchar(str[i]);
		i++;
	}
	return (len);
}
