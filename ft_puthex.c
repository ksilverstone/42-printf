/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgumusta <kgumusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:29:58 by kgumusta          #+#    #+#             */
/*   Updated: 2024/12/06 15:35:42 by kgumusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int i, char x)
{
	int	char_count;

	char_count = 0;
	if (i >= 16)
	{
		char_count += ft_puthex(i / 16, x);
	}
	if (x == 'x')
	{
		if (ft_putchar("0123456789abcdef"[i % 16]) == -1)
			return (-1);
	}
	else if (x == 'X')
	{
		if (ft_putchar("0123456789ABCDEF"[i % 16]) == -1)
			return (-1);
	}
	return (++char_count);
}
