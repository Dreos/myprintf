/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:16:00 by lloisel           #+#    #+#             */
/*   Updated: 2022/04/23 19:07:47 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXA "0123456789abcdef"
# define CONV "cspdiuxX%"
# define NBCV 9

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		isconvert(char c);
int		ft_printf(const char *fmt, ...);
int		sizehex(unsigned long long a);
int		ft_toupper(int c);
int		display_c(va_list *ap);
int		display_s(va_list *ap);
int		display_p(va_list *ap);
int		display_d(va_list *ap);
int		display_i(va_list *ap);
int		display_u(va_list *ap);
int		display_x(va_list *ap);
int		display_xmaj(va_list *ap);
int		display_percent(void);
char	*itoh(unsigned long a, char *str);
char	*ft_itoa(long int i);

#endif
