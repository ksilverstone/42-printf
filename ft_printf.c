/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgumusta <kgumusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:42:49 by kgumusta          #+#    #+#             */
/*   Updated: 2024/11/26 19:30:05 by kgumusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int format_func(const char *format, va_list args)
{
    int char_count;

    char_count = 0;
    if (*format == 'c')
		return (char_count += ft_putchar((char)va_arg(args, int)));
	else if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'd' || c == 'i')
		return (ft_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_nbr(va_arg(args, unsigned int)));
	else if (c == 's')
		return (ft_string(va_arg(args, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_point(va_arg(args, void *)));
	else
		return (-1);

}