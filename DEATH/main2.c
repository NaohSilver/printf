/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 23:40:34 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/25 19:13:49 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
/*
manque -, champ min
refair h, hh, c, C, +, 0
bonus n, couleur, eE fF gG aA * $ L fd
*/

int main()
{
	int d;
	char *s;

	d = 555;
	s = "yolo";
	ft_printf("la valeur est %012.2lld\n", 555);
	return (0);
}
