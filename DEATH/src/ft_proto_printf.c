/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proto_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 02:33:33 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/24 20:23:01 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

//fair le ft_rebuffer mais avec le s

t_arg *ft_rebuffer(t_arg *proto)
{
	char new[proto->precis];
	int i;
	int u;
	int i2;

	i = -1;
	i2 = -1;
	u = proto->precis - proto->len2;
	//fair les ft_beforflag
	while (++i != proto->precis)
	{
		if (i > u && ++i2)
			new[i] = proto->rebuffer[i2];
		else
			new[i] = ' ';
	}
	return (proto);
}

t_arg *ft_travaille(t_arg *proto, va_list ap)
{
	int i;

	i = -1;
	proto->rebuffer = ft_yolo(proto, ap);
	proto->len2 = ft_strlen(proto->rebuffer);
	while (++i <= proto->len2)
	{
		ft_putstr(proto->rebuffer);
		proto->buffer[proto->len] = proto->rebuffer[i];
		proto->len += 1;
	}
	return (proto);
}
