/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgumusta <kgumusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:56 by kgumusta          #+#    #+#             */
/*   Updated: 2024/11/26 19:30:07 by kgumusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_string(char *s)
{
    int check;
    int i;
    
    i = 0;
    check = 0;
    if (s == NULL)
    	return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		check = write(1, &(s[i++]), 1);
		if (check == -1)
			return (-1);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int char_count;

	char_count = 0;
	if(n == -2147483648)
	{
		if(ft_putchar("-2147483648") == -1)
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

int	ft_hex(unsigned int i, char x)
{
	int char_count;

	char_count = 0;
	if (i >= 16)
	{
		char_count += ft_hex(i / 16, x);
	}
	if (x == 'x')
	{
		if(ft_putchar("0123456789abcdef"[i % 16]) == -1);
			return (-1);
	}
	else if (x == 'X')
	{
		if(ft_putchar("0123456789abcdef"[i % 16]) == -1);
			return (-1);
	}
	return (++char_count);
}
