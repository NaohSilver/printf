/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_befor_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 04:58:10 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/10 05:27:08 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_arg *ft_space(t_arg *proto, va_list ap)
{
	if (proto->conver == 'i')
	{
		ft_strcat(proto->buffer, " ");
		ft_strcat(proto->buffer, ft_get_base(va_arg(ap, int), 10, '.'));
		return (proto);
	}
	else if (proto->conver == 'd')
	{
		ft_strcat(proto->buffer, " ");
		ft_strcat(proto->buffer, ft_get_base(va_arg(ap, int), 10, '.'));
		return (proto);
	}
	else
		return (proto);
}

t_arg *ft_plus(t_arg *proto, va_list ap)
{
	if (proto->conver == 'i')
	{
		ft_strcat(proto->buffer, "+");
		ft_strcat(proto->buffer, ft_get_base(va_arg(ap, int), 10, '.'));
		return (proto);
	}
	else
		return(proto);
}

static char *ft_bolosse(t_arg *proto, va_list ap)
{
	a faire urgent;
}

t_arg *ft_diese(t_arg *proto, va_list ap)
{
	if (proto->conver == 'x')
	{
		proto->rebuffer = ft_bolosse(proto, ap);
		proto->len = ft_strlen(proto->rebuffer);
		ft_strncat(proto->buffer, proto->rebuffer, proto->len);
		write(1, proto->buffer, BUFF_SIZE);
		return (proto);
	}
	else if (proto->conver == 'X')
	{
		ft_strcat(proto->buffer, "0X");
		ft_strcat(proto->buffer, ft_get_base(va_arg(ap, unsigned int), 16, 'A'));
		return (proto);
	}
	else if (proto->conver == 'o')
	{
		ft_strcat(proto->buffer, "0");
		ft_strcat(proto->buffer, ft_get_base(va_arg(ap, int), 8, '.'));
		return (proto);
	}
	else if (proto->conver == 'O')
	{
		ft_strcat(proto->buffer, "0");
		ft_strcat(proto->buffer, ft_get_base(va_arg(ap, long), 8, '.'));
		return (proto);
	}
	else
		return (proto);
}
