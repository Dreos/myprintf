/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:23:09 by lloisel           #+#    #+#             */
/*   Updated: 2022/04/23 18:02:28 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	display_c(va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	write(1, &c, 1);
	return (1);
}

int	display_s(va_list *ap)
{
	const char	*s;
	int			nb;

	nb = 0;
	s = va_arg(*ap, const char *);
	if (!(s))
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		nb++;
	}
	return (nb);
}

int	display_p(va_list *ap)
{
	char			*str;
	unsigned long	val;
	int				size;

	val = (unsigned long) va_arg(*ap, void *);
	if (!(val))
	{
		write(1, "(nil)", 5);
		return (5);
	}
	size = (int)sizehex(val);
	str = malloc(size + 1);
	if (!(str))
		return (0);
	str[size] = '\0';
	itoh(val, str);
	write(1, "0x", 2);
	write(1, str, size);
	free(str);
	return (size + 2);
}

int	display_d(va_list *ap)
{
	int		nb;
	char	*str;

	nb = va_arg(*ap, int);
	str = ft_itoa(nb);
	if (!(str))
		return (0);
	nb = 0;
	while (str[nb])
	{
		write(1, (str + nb), 1);
		nb++;
	}
	free(str);
	return (nb);
}

int	display_i(va_list *ap)
{
	int		nb;
	char	*str;

	nb = va_arg(*ap, int);
	str = ft_itoa(nb);
	if (!(str))
		return (0);
	nb = 0;
	while (str[nb])
	{
		write(1, (str + nb), 1);
		nb++;
	}
	free(str);
	return (nb);
}
