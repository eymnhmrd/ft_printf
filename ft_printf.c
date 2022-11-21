/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 00:19:42 by ahamrad           #+#    #+#             */
/*   Updated: 2022/11/21 02:09:41 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_percent(va_list list, char c, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(list, int), count);
	if (c == 's')
		ft_putstr(va_arg(list, char *), count);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(list, int), count);
	if (c == 'u')
		ft_putunsigned(va_arg(list, unsigned int), count);
	if (c == '%')
		ft_putchar('%', count);
	if (c == 'x')
		ft_puthexa_x(va_arg(list, unsigned int), count);
	if (c == 'X')
		ft_puthexa_xmaj(va_arg(list, unsigned int), count);
	if (c == 'p')
	{
		ft_putstr("0x", count);
		ft_puthexa_x(va_arg(list, unsigned long), count);
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	list;

	i = 0;
	count = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_check_percent(list, format[i], &count);
		}
		else
		{
			ft_putchar(format[i], &count);
		}
		i++;
	}
	return (count);
}
