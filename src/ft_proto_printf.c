/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proto_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 02:33:33 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/10 05:16:59 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_arg *ft_travaille_tranquille(t_arg *proto, va_list ap)
{
	return (proto);
}

t_arg *ft_travaille_dur(t_arg *proto, va_list ap)
{
	return (proto);
}

t_arg *ft_travaille_facile(t_arg *proto, va_list ap)
{
	return (proto);
}

t_arg *ft_travaille_oklm(t_arg *proto, va_list ap)
{
	if (proto->befor_flag == 1)
		proto = ft_diese(proto, ap);
	else if (proto->befor_flag == 2)
		proto = ft_plus(proto, ap);
	else if (proto->befor_flag == 4)
		proto = ft_space(proto, ap);
	return (proto);
}

t_arg *ft_travaille(t_arg *proto, va_list ap)
{
	int len;

	len = 0;
	if ((proto->precis != 0) && (proto->weidth != 0) && (proto->flag
		!= 0) && (proto->befor_flag != 0))
		return (ft_travaille_dur(proto, ap));
	else if ((proto->flag != 0) && (proto->befor_flag != 0))
		return (ft_travaille_tranquille(proto, ap));
	else if (proto->flag != 0)
		return (ft_travaille_facile(proto, ap));
	else if (proto->befor_flag != 0)
		return (ft_travaille_oklm(proto, ap));
	else
	{
		proto->rebuffer = ft_yolo(proto, ap);
		proto->len = ft_strlen(proto->rebuffer);
		ft_strncat(proto->buffer, proto->rebuffer, proto->len);
		write(1, proto->buffer, BUFF_SIZE);
		return (proto);
	}
}
