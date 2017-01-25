/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:38:50 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/25 19:19:46 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void ft_posey2(char *format, t_arg *proto)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while (format[i] != '\0')
	{
		if (ft_isdigit(format[i]) == 1 && format[i - 1] != '.')
		{
			while (ft_isdigit(format[i]) == 1)
			{
				proto->nbr[i2] = format[i];
				i++;
				i2++;
			}
			proto->weidth = ft_atoi(proto->nbr);
			ft_putnbr(proto->weidth);
		}
		else if (ft_isdigit(format[i]) == 1 && format[i - 1] == '.')
		{
			i2 = 0;
			while (ft_isdigit(format[i]) == 1)
			{
				proto->nbr2[i2] = format[i];
				i++;
				i2++;
			}
			proto->precis = ft_atoi(proto->nbr2);
			ft_putnbr(proto->precis);
		}
		else
			i++;
	}
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
		if (ft_verif_flagg(format[len], format[len + 1], proto) != 0 \
		&& (proto->flag == 0))
		{
			if (ft_verif_flagg(format[len], format[len + 1], proto) == 1
			|| ft_verif_flagg(format[len], format[len + 1], proto) == 2)
				len--;
			proto->flag = ft_verif_flagg(format[len], format[len - 1], proto);
			len--;
		}
		if (ft_verif_befor(format[len], proto) != 0)
		{
			proto->befor_flag = ft_verif_befor(format[len], proto);
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
		ft_posey2(str, proto);
//		proto = ft_travaille(proto, ap);
		return (proto);
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_arg		*proto;

	if (!(proto = (t_arg*)malloc(sizeof(t_arg))))
		return (0);
	va_start(ap, format);
	while (*format != '\0')
	{
		while (*format != '%' && *format)
		{
			proto->buffer[proto->len] = *format;
			format++;
			proto->len += 1;
		}
		if (*format == '%')
		{
			++format;
			proto = ft_get_param((&format), ap, proto);
			while (proto->len2 != 0 && ++format)
				proto->len2 -= 1;
		}
	}
	write(1, proto->buffer, BUFF_SIZE);
	va_end(ap);
	return (proto->len);
}
