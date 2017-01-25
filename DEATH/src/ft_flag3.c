/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:11:27 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/24 20:17:27 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int ft_verif_last(const char *format)
{
	if (*format == 's' || *format == 'S' || *format == 'p' || *format == 'd' ||
	*format == 'D' || *format == 'i' || *format == 'o' || *format == 'O' ||
	*format == 'u' || *format == 'U' || *format == 'x' || *format == 'X' ||
	*format == 'c' || *format == 'C' || *format == 'B' || *format == 'b' ||
	*format == 'p')
		return (1);
	else
		return (0);
}

int ft_check_last(char format)
{
	if (format == 's' || format == 'S' || format == 'p' || format == 'd' ||
	format == 'D' || format == 'i' || format == 'o' || format == 'O' ||
	format == 'u' || format == 'U' || format == 'x' || format == 'X' ||
	format == 'c' || format == 'C' || format == 'B' || format == 'b' ||
	format == 'p')
		return (1);
	else
		return (0);
}

char ft_conv(const char *format)
{
	if (ft_verif_last(format) == 1)
		return (*format);
	else
		return ('z');
}

char ft_return(const char *format)
{
	return ((char)*format);
}

int ft_preci(char format, char format2)
{
	if (ft_isdigit((int)format) == 1)
	{
		if ((ft_isdigit(format) == 1) && (ft_isdigit(format2) == 1))
			return (1);
		else if (format == '.' && ft_isdigit(format2) == 1)
			return (2);
		else if (format == '*' && ft_isdigit(format2) == 1)
			return (3);
		else if (format2 == '.')
			return (4);
		else if (format2 == '*')
			return (5);
		else
			return (6);
	}
	else
		return (0);
}
