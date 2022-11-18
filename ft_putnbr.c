/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:45:04 by ahamrad           #+#    #+#             */
/*   Updated: 2022/11/17 22:27:54 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, count);
		ft_putchar(nbr % 10 + 48, count);
	}
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + 48, count);
}

// int main()
// {
// 	int count = 0;
// 	ft_putnbr(-12345, &count);
// 	printf("\n%d", count);
// }