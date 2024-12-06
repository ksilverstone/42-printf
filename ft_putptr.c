/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgumusta <kgumusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:33:26 by kgumusta          #+#    #+#             */
/*   Updated: 2024/12/06 16:53:23 by kgumusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_static_hexa(unsigned long i)
{
	int	char_count;

	char_count = 0;
	if (i >= 16)
		char_count += ft_static_hexa(i / 16);
	if (ft_putchar("0123456789abcdef"[i % 16]) == -1)
		return (-1);
	char_count++;
	return (char_count);
}

int	ft_putptr(void *p)
{
	unsigned long	i;
	int				char_count;

	i = (unsigned long)p;
	char_count = 0;
	if (!i)
	{
		if (ft_putstr("(nil)") == -1)
			return (-1);
		return (5);
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	char_count = 2;
	char_count += ft_static_hexa(i);
	return (char_count);
}
