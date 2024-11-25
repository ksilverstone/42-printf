/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgumusta <kgumusta@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:42:49 by kgumusta          #+#    #+#             */
/*   Updated: 2024/11/05 14:53:34 by kgumusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int ft_check(char f)
{
	return (f == 'c' || f == 'd' || f == 'i' || f == 'u' || f == '%'
		|| f == 's' || f == 'x' || f == 'X' || f == 'p');
}

int ft_format(va_list arr, char format)
{
    if(format == 'c')
        return(ft_putchar(va_arg(arr, int)));
    else if(format ==)
}