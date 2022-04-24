/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:56:53 by lloisel           #+#    #+#             */
/*   Updated: 2022/04/24 13:15:42 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include  <string.h>

static int	display(char a, va_list *ap)
{	
	int	size;	

	size = 0;
	if (a == 'c')
		size = display_c(ap);
	if (a == 's')
		size = display_s(ap);
	if (a == 'p')
		size = display_p(ap);
	if (a == 'd')
		size = display_d(ap);
	if (a == 'i')
		size = display_i(ap);
	if (a == 'u')
		size = display_u(ap);
	if (a == 'x')
		size = display_x(ap);
	if (a == 'X')
		size = display_xmaj(ap);
	if (a == '%')
		size = display_percent();
	return (size);
}

char	*itoh(unsigned long a, char *str)
{
	if (a / 16 == 0)
	{	
		*str = HEXA[a % 16];
		return (str + 1);
	}
	else
	{
		str = itoh(a / 16, str);
		*str = HEXA[a % 16];
		return (str + 1);
	}
}

int	sizehex(unsigned long long a)
{
	int	i;

	i = 1;
	while (a / 16 != 0)
	{
		a = a / 16;
		i++;
	}
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		size;

	size = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			write(1, fmt, 1);
			size++;
		}
		else
		{
			fmt++;
			size += display(*(fmt), &ap);
		}
		fmt++;
	}
	va_end(ap);
	return (size);
}
