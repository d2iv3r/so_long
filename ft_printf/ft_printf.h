/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:06:09 by efarhat           #+#    #+#             */
/*   Updated: 2022/11/25 19:49:35 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_prtchar(char c);
int	ft_prtstr(char *str);
int	ft_prtnbr(int nb);
int	ft_prthexa(unsigned long long n, int type);
int	ft_prtuni(unsigned int nb);

#endif
