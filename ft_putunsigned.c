/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:18:22 by ahamrad           #+#    #+#             */
/*   Updated: 2022/11/18 03:23:19 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_putunsigned(n / 10, count);
		ft_putchar(n % 10 + 48, count);
	}
	else
		ft_putchar(n % 10 + 48, count);
}
