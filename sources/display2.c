/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:41:16 by lloisel           #+#    #+#             */
/*   Updated: 2022/04/23 00:54:33 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_toupper(int c )
{
	if (c >= 97 && c <= 122)
	{
		return(c - 32);
	}
	else
	{
		return (c);
	}	
}
int display_u(va_list *ap)
{
	unsigned int nb;
	char *str;

	nb = va_arg(*ap,unsigned int);
	str = ft_itoa(nb);
	nb= 0;
	while (str[nb])
	{
		write(1,(str+nb),1);
		nb++;
	}
	free(str);
	return (nb);			
}
int display_x(va_list *ap)
{
	char *str;
	int size;
	unsigned int val;
		
	val = va_arg(*ap,unsigned int);
	size = (int)sizehex(val);
	str = malloc(size + 1);
	str[size]= '\0';
	itoh(val,str);
	write(1, str, size);
	free(str);
	return(size);
}

int display_X(va_list *ap)
{
	char *str;
	int size;
	unsigned int val;
		
	val = va_arg(*ap,int);
	size = (int)sizehex(val);
	str = malloc(size + 1);
	str[size]= '\0';
	itoh(val,str);
	size = 0;
	while(str[size])
	{
		str[size] = ft_toupper(str[size]);
		write(1,(str + size),1);
		size++;
	}
	free(str);
	return(size);
}

int display_percent(void)
{
	write(1,"%",1);
	return(1);
}
