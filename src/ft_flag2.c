/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:37:58 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/09 15:49:34 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int ft_verif_flagg(char format, char format2)
{
	if (format == 'l' && format2 == 'l')
		return (1);
	else if (format == 'h' && format2 == 'h')
		return (2);
	else if (format == 'j')
		return (3);
	else if (format == 'l')
		return (4);
	else if (format == 'h')
		return (5);
	else if (format == 'z')
		return (6);
	else
		return (0);
}

int ft_verif_befor(char format)
{
	if (format == '#')
		return (1);
	else if (format == '+')
		return (2);
	else if (format == '-')
		return (3);
	else if (format == ' ')
		return (4);
	else if (format == '0')
		return (5);
	else
		return (0);
}
/*
char		*ft_poney_hh(const char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		return (ft_get_base(va_arg(ap, signed char), 10, '.'));
	else if (*format == 'o')
		return (ft_get_base(va_arg(ap, unsigned char), 8, '.'));
	else if (*format == 'u')
		return (ft_get_base(va_arg(ap, unsigned char), 10, '.'));
	else if (*format == 'x')
		return (ft_get_base(va_arg(ap, unsigned char), 16, 'a'));
	else if (*format == 'X')
		return (ft_get_base(va_arg(ap, unsigned char), 16, 'A'));
}

char		*ft_poney_h(const char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		return (ft_get_base(va_arg(ap, short), 10, '.'));
	else if (*format == 'o')
		return (ft_get_base(va_arg(ap, unsigned short), 8, '.'));
	else if (*format == 'u')
		return (ft_get_base(va_arg(ap, unsigned short), 10, '.'));
	else if (*format == 'x')
		return (ft_get_base(va_arg(ap, unsigned short), 16, 'a'));
	else if (*format == 'X')
		return (ft_get_base(va_arg(ap, unsigned short), 16, 'A'));
}

char		*ft_poney_size(const char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		return (ft_get_base(va_arg(ap, unsigned int), 10, '.'));
	else if (*format == 'o')
		return (ft_get_base(va_arg(ap, size_t), 8, '.'));
	else if (*format == 'u')
		return (ft_get_base(va_arg(ap, size_t), 10, '.'));
	else if (*format == 'x')
		return (ft_get_base(va_arg(ap, size_t), 16, 'a'));
	else if (*format == 'X')
		return (ft_get_base(va_arg(ap, size_t), 16, 'A'));
}
*/
