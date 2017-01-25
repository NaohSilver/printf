/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:30:53 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/24 20:14:14 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		len_base(long nb, int base)
{
	int			len;

	len = 1;
	while (nb >= base)
	{
		len++;
		nb /= base;
	}
	return (len);
}

static char		*get_tab(int base, char c)
{
	int			i;
	char		*tab;

	i = 0;
	tab = (char*)malloc(sizeof(char) * base + 1);
	if (tab)
	{
		while (i < base)
		{
			if (i < 10)
				tab[i] = i + 48;
			else
				tab[i] = c++;
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}

char			*ft_get_base_2(long nb, int base, char c, t_arg *proto)
{
	char		*content;
	int			len;
	char		*tab;

	if (base > 16)
		return (NULL);
	if (base == 10 && nb < 10)
		return (ft_itoa(nb));
	tab = get_tab(base, c);
	if (proto->precis != 0)
		len = proto->precis;
	else if (proto->precis == 0 && proto->weidth != 0)
		len = proto->weidth;
	else
		len = len_base(nb, base);
	if (!(content = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (content)
	{
		content[len--] = '\0';
		while (len > (len - ft_strlen(tab)))
		{
			content[len] = tab[nb % base];
			nb /= base;
			len--;
		}
		if (len != 0)
		{
			++len;
			if (proto->precis != 0)
			{
				while (len > 0 && --len)
					content[len] = ' ';
			}
		}
		content[len] = tab[nb];
		return (content);
	}
	return (NULL);
}
