/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:19:42 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/24 00:28:35 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char *ft_bool(int ap)
{
	char *content;

	if (ap == 1)
	{
		content = (char *)malloc(sizeof(char) * 5);
		content = "true";
		return (content);
	}
	else if (ap == 0)
	{
		content = (char *)malloc(sizeof(char) * 6);
		content = "false";
		return (content);
	}
	else
	{
		content = (char *)malloc(sizeof(char) * 12);
		content = "not boolean";
		return (content);
	}
}

/*char		*ft_poney_intmax(const char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		return (ft_get_base(va_arg(ap, intmax_t), 10, '.'));
	else if (*format == 'o')
		return (ft_get_base(va_arg(ap, uintmax_t), 8, '.'));
	else if (*format == 'u')
		return (ft_get_base(va_arg(ap, uintmax_t), 10, '.'));
	else if (*format == 'x')
		return (ft_get_base(va_arg(ap, uintmax_t), 16, 'a'));
	else if (*format == 'X')
		return (ft_get_base(va_arg(ap, uintmax_t), 16, 'A'));
}

char		*ft_poney_ll(const char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		return (ft_get_base(va_arg(ap, long long), 10, '.'));
	else if (*format == 'o')
		return (ft_get_base(va_arg(ap, unsigned long long), 8, '.'));
	else if (*format == 'u')
		return (ft_get_base(va_arg(ap, unsigned long long), 10, '.'));
	else if (*format == 'x')
		return (ft_get_base(va_arg(ap, unsigned long long), 16, 'a'));
	else if (*format == 'X')
		return (ft_get_base(va_arg(ap, unsigned long long), 16, 'A'));
}

char		*ft_poney_l(const char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		return (ft_get_base(va_arg(ap, long), 10, '.'));
	else if (*format == 'o')
		return (ft_get_base(va_arg(ap, unsigned long), 8, '.'));
	else if (*format == 'u')
		return (ft_get_base(va_arg(ap, unsigned long), 10, '.'));
	else if (*format == 'x')
		return (ft_get_base(va_arg(ap, unsigned long), 16, 'a'));
	else if (*format == 'X')
		return (ft_get_base(va_arg(ap, unsigned long), 16, 'A'));
}
*/

char	*ft_yolo(t_arg *proto, va_list ap)
{
	if (proto->conver == 's')
		return (va_arg(ap, char *));
	else if (proto->conver == 'd' || proto->conver == 'i')
		return (ft_get_base_2(va_arg(ap, int), 10, '.', proto));
	else if (proto->conver == 'D')
		return (ft_get_base(va_arg(ap, long), 10, '.'));
	else if (proto->conver == 'o')
		return (ft_get_base(va_arg(ap, int), 8, '.'));
	else if (proto->conver == 'O')
		return (ft_get_base(va_arg(ap, long), 8, '.'));
	else if (proto->conver == 'u')
		return (ft_get_unsigned_base(va_arg(ap, unsigned int), 10, '.'));
	else if (proto->conver == 'U')
		return (ft_get_unsigned_base(va_arg(ap, unsigned long), 10, '.'));
	else if (proto->conver == 'x')
		return (ft_get_unsigned_base(va_arg(ap, unsigned int), 16, 'a'));
	else if (proto->conver == 'X')
		return (ft_get_unsigned_base(va_arg(ap, unsigned int), 16, 'A'));
	else if (proto->conver == 'b')
		return (ft_get_base(va_arg(ap, int), 2, '.'));
	else if (proto->conver == 'p')
		return (ft_strcat("0x", ft_get_unsigned_base(va_arg(ap, unsigned long),
		 16, 'a')));
	else if (proto->conver == 'B')
	 	return (ft_bool(va_arg(ap, int)));
	else
		return (NULL);
}
