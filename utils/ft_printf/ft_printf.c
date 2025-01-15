/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:04:34 by efarhat           #+#    #+#             */
/*   Updated: 2022/11/26 10:24:45 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prntype(va_list ap, char con)
{
	int	len;

	len = 0;
	if (con == 'c')
		len += ft_prtchar(va_arg(ap, int));
	else if (con == 's')
		len += ft_prtstr(va_arg(ap, char *));
	else if (con == 'd' || con == 'i')
		len += ft_prtnbr(va_arg(ap, int));
	else if (con == 'p')
	{
		len += ft_prtstr("0x");
		len += ft_prthexa((unsigned long long)va_arg(ap, void *), 87);
	}
	else if (con == 'u')
		len += ft_prtuni(va_arg(ap, unsigned int));
	else if (con == 'x')
		len += ft_prthexa(va_arg(ap, unsigned int), 87);
	else if (con == 'X')
		len += ft_prthexa(va_arg(ap, unsigned int), 55);
	else if (con == '%')
		len += ft_prtchar('%');
	else if (con != '\0')
		len += ft_prtchar(con);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	ap;
	int		len;

	va_start(ap, s);
	i = 0;
	len = 0;
	if (write(1, "0", 0) == -1)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			len += ft_prntype(ap, s[i + 1]);
			i++;
		}
		else
			len += ft_prtchar(s[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
