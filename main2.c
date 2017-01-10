/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 23:40:34 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/10 03:44:52 by niludwig         ###   ########.fr       */
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
	ft_printf("la valeur est %B\n", 1);
	return (0);
}
