/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgumusta <kgumusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:42:49 by kgumusta          #+#    #+#             */
/*   Updated: 2024/12/06 16:52:11 by kgumusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_func(const char *format, va_list args)
{
	int	char_count;

	char_count = 0;
	if (*format == 'c')
		return (char_count += ft_putchar(va_arg(args, int)));
	else if (*format == 's')
		return (char_count += ft_putstr(va_arg(args, char *)));
	else if (*format == 'd' || *format == 'i')
		return (char_count += ft_putnbr(va_arg(args, int)));
	else if (*format == 'u')
		return (char_count += ft_putnbr_u(va_arg(args, unsigned int)));
	else if (*format == 'x' || *format == 'X')
		return (char_count += ft_puthex(va_arg(args, unsigned int), *format));
	else if (*format == 'p')
		return (char_count += ft_putptr(va_arg(args, void *)));
	else if (*format == '%')
		return (char_count += ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		char_count;
	int		tmp;

	if (!format)
		return (-1);
	va_start(args, format);
	char_count = 0;
	while (*format)
	{
		if (*format == '%' && *(++format))
			tmp = format_func(format, args);
		else if (*format != '%')
			tmp = ft_putchar(*format);
		if (tmp == -1)
			return (-1);
		char_count += tmp;
		format++;
	}
	va_end(args);
	return (char_count);
}
