/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:56:53 by lloisel           #+#    #+#             */
/*   Updated: 2022/02/01 13:30:14 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
	
void display(char a,va_list *ap)
{
	char *s;
	int i;
	char c;
	

	if(a == 's')
	{
		s =(char *) va_arg(*ap,char *);
		while(*s)
		{
			write(1,s,1);
			s++;
		}
	}
	if(a == 'c')
	{
		c = (char) va_arg(*ap,int);
		write(1,&c,1);
	}	
	if(a == 'd')
	{
		i = (int) va_arg(*ap,int);
		printf("%d",i);		
	}
}

int test(const char *fmt,...)
{
	va_list ap;
	va_start(ap, fmt);
	while(*fmt)
	{
		if(*fmt == '%')
		{
			fmt++;
			if(*fmt)
				display(*fmt,&ap);
		}
		else
			write(1,fmt,1);
		fmt++;
	}
	va_end(ap);
	return(0);
}

int main()
{	
	test("aze %s %s %s %d \n","jean","mouloud","jack",1);
}
