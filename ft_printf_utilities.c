/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgumusta <kgumusta@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:56 by kgumusta          #+#    #+#             */
/*   Updated: 2024/11/25 17:09:17 by kgumusta         ###   ########.fr       */
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
		check = write (1, &(s[i++]), 1);
		if (check == -1)
			return (-1);
	}
	return (i);
}

int ft_int(int n)
{
    
}