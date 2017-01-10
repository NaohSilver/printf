/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:38:50 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/10 03:47:14 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_arg *ft_posey2(char *format, t_arg *proto, va_list ap)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while (*format)
	{
		if (ft_isdigit(*format) == 1)
		{
			proto->nbr[i] = *format;
			format++;
			++i;
		}
		else if (*format == '.')
		{
			format++;
			while (ft_isdigit(*format) == 1)
			{
				proto->nbr2[i2] = *format;
				format++;
				i2++;
			}
		}
		else if (*format == '*')
		{
			format++;
			if (*format == '.')
			{
				proto->precis = va_arg(ap, int);
				proto->boul = 1;
			}
			else
			{
				proto->weidth = va_arg(ap, int);
				proto->boul = 0;
			}
			format++;
		}
		else
			format++;
	}
	if (proto->boul == 1)
	{
		proto->weidth = ft_atoi(proto->nbr);
	}
	if (proto->boul == 0)
	{
		proto->precis = ft_atoi(proto->nbr2);
	}
	ft_putstr("precis ==");
	ft_putnbr(proto->precis);
	ft_putchar('\n');
	ft_putstr("weidth ==");
	ft_putnbr(proto->weidth);
	ft_putchar('\n');
	return (proto);
}

static t_arg *ft_posey(char *format, t_arg *proto)
{
	int len;

	len = ft_strlen(format);
	while (len != -1)
	{
		len--;
		if (ft_check_last(format[len]) != 0)
		{
			proto->conver = ft_check_last(format[len]);
			len--;
		}
		if (ft_verif_flagg(format[len], format[len - 1]) != 0)
		{
			if (ft_verif_flagg(format[len], format[len - 1]) == 1
			|| ft_verif_flagg(format[len], format[len - 1]) == 2)
				len--;
			proto->flag = ft_verif_flagg(format[len], format[len - 1]);
			len--;
		}
		if (ft_verif_befor(format[len]) != 0)
		{
			proto->befor_flag = ft_verif_befor(format[len]);
			len--;
		}
	}
	return (proto);
}


static t_arg *ft_get_param(const char **format, va_list ap, t_arg *proto)
{
	int i;
	char *str;

	i = 0;
	str = (char *)malloc(sizeof(char) * 5000);
	if (ft_verif_last(*format) == 1)
	{
		proto->conver = ft_conv(*format);
		i++;
		proto = ft_travaille(proto, ap);
		return (proto);
	}
	else
	{
		while (ft_verif_last(*format) != 1)
		{
			str[i] = ft_return(*format);
			i++;
			(*format)++;
			if (ft_verif_last(*format) == 1)
			{
				proto->conver = ft_conv(*format);
				i++;
			}
		}
		i++;
		str[i] = '\0';
		proto = ft_posey(str, proto);
		proto = ft_posey2(str, proto, ap);
		proto = ft_travaille(proto, ap);
		return (proto);
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_arg		*proto;
	int i;

	i = 0;
	proto = (t_arg*)malloc(sizeof(t_arg));
	va_start(ap, format);
	while (*format != '\0')
	{
		while (*format != '%' && *format)
		{
			proto->buffer[i] = *format;
			format++;
			i++;
		}
		if (*format == '%')
		{
			++format;
			proto = ft_get_param((&format), ap, proto);
			i += proto->len;
		}
	}
	proto->buffer[i] = '\0';
	i = 0;
	while (proto->buffer[i] != '\0')
		i++;
	write(1, proto->buffer, BUFF_SIZE);
/*	ft_putstr("convertiseur ==");
	ft_putchar(proto->conver);
	ft_putchar('\n');
	ft_putstr("gros flag ==");
	ft_putnbr(proto->flag);
	ft_putchar('\n');
	ft_putstr("premier flag ==");
	ft_putnbr(proto->befor_flag);
	ft_putchar('\n');*/
	va_end(ap);
	return (i);
}
