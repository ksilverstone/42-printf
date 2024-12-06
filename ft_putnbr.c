/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgumusta <kgumusta@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:28:50 by kgumusta          #+#    #+#             */
/*   Updated: 2024/12/04 14:29:32 by kgumusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int char_count;

	char_count = 0;
	if(n == -2147483648)
	{
		if(ft_putstr("-2147483648") == -1)
			return (-1);
		return (11);
	}
	if(n < 0)
	{
		if(ft_putchar('-') == -1)
			return (-1);
		n *= -1;
		char_count++;
	}
	if(n >= 10)
		char_count += ft_putnbr(n / 10);
	if(ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (++char_count);
}

int ft_putnbr_u(unsigned int n)
{
	int char_count;

	char_count = 0;
	if(n >= 10)
		char_count += ft_putnbr_u(n);
	if(ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (++char_count);
}