/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:45:29 by lloisel           #+#    #+#             */
/*   Updated: 2022/04/24 13:31:32 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}	
}

static long int	nbdigit(long int i)
{
	long int	size;

	size = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		size++;
	}
	while (i != 0)
	{
		size++;
		i = i / 10;
	}
	return (size);
}

static char	*convert(char *s, long int i)
{
	if (i / 10 == 0)
	{
		*s = i + '0';
		return (s + 1);
	}
	s = convert(s, i / 10);
	*s = i % 10 + '0';
	return (s + 1);
}

char	*ft_itoa(long int i)
{
	char		*s;
	int			size;
	long int	j;

	j = i;
	size = nbdigit(j);
	s = malloc(size + 1);
	if (!(s))
		return (0);
	s[size] = '\0';
	if (j < 0)
	{
		*s = '-';
		convert(s + 1, -j);
	}
	else
	{	
		convert(s, j);
	}
	return (s);
}

int	isconvert(char c)
{
	int		i;
	char	*convert;

	convert = "cspdiuxX%";
	i = 0;
	while (i < 9)
	{
		if (c == convert[i])
			return (1);
		i++;
	}
	return (0);
}
