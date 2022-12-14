/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:07:56 by ahamrad           #+#    #+#             */
/*   Updated: 2022/11/21 07:54:01 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_x(unsigned long n, int *count)
{
	char	*b;

	b = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthexa_x(n / 16, count);
		ft_puthexa_x(n % 16, count);
	}
	if (n <= 15)
		ft_putchar(b[n % 16], count);
}

void	ft_puthexa_xmaj(unsigned long n, int *count)
{
	char	*b;

	b = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_puthexa_xmaj(n / 16, count);
		ft_puthexa_xmaj(n % 16, count);
	}
	if (n <= 15)
		ft_putchar(b[n % 16], count);
}
