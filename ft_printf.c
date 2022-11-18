/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 00:19:42 by ahamrad           #+#    #+#             */
/*   Updated: 2022/11/18 05:33:11 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (format[i] == 'c')
				ft_putchar(va_arg(list, int), &count);
			if (format[i] == 's')
				ft_putstr(va_arg(list, char *), &count);
			if (format[i] == 'd' || format[i] == 'i')
				ft_putnbr(va_arg(list, int), &count);
			if (format[i] == 'u')
				ft_putunsigned(va_arg(list, unsigned int), &count);
			if (format[i] == '%')
				ft_putchar('%', &count);
			if (format[i] == 'x')
				ft_puthexa_x(va_arg(list, unsigned long), &count);
			if (format[i] == 'X')
				ft_puthexa_xmaj(va_arg(list, unsigned long), &count);
			if (format[i] == 'p')
			{
				ft_putstr("0x", &count);
				ft_puthexa_x(va_arg(list, unsigned long), &count);
			}
		}
		else
		{
			ft_putchar(format[i], &count);
		}
		i++;
	}
	return (count);
}
