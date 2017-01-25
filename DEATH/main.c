/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 08:36:47 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/06 19:26:26 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
/*
s : string ()| S : s l modifier (0)| p : void * en hexa ()| d : int ()| D : long ()|
i : signed int ()| o : base 8 ()| O : unsigned o ()| u : unsigned d/i () | U : unsigned long ()|
x : hexa ()| X : maj x ()| c : int -> unsigned char ecrit ()| C : c with l ()
one space for d i
!: take no argument and flush the output.
,: take no argument and output nothing: a no-op delimiter for conversion specifications.
-: left-justify the output (default is right justification).
0: for numerical conversions, pad with zeroes instead of spaces.
+: for signed numerical conversions, prefix number with a + sign if positive.
*/

int	main(int ac, char **av)
{
	int c;
	long c3;
	void *t;
	int *s;
	long c2;
	short shor;
	unsigned long yolo;
	char vio;
	int cc;
	double doublei;

	doublei = 5454654;
	cc = -250;
	vio = '1';
	yolo = 120;
	shor = 20;
	c = 4545;
	c2 = 23;
	c3 = 28;
	s = (int *)malloc(sizeof(int) * 4);
	*s = c;
	printf("%#-12llx\n", (unsigned long long)42); 
	printf("salut %#00000o for c\n", c);
	printf("%d for c\n", c);
	printf("%+d for +c\n", cc);
	printf("%hhd for hd\n", vio);
	printf("%s for s\n", "yolo");
	printf("% 0d for 0d\n",  1212);
	printf("%S for S\n", s);
	printf("%p for p\n", t);
	printf("%ld for ld\n", c3);
	printf("%d for d\n", c);
	printf("%D for D\n", c);
	printf("%i for i\n", c);
	printf("%o for o\n", c);
	printf("%O for O\n", c);
	printf("%u for u\n", c);
	printf("%U for U\n", c);
	printf("%x for x\n", c);
	printf("%X for X\n", 254621);
	printf("%c for c\n", 'a');
	printf("%C for C\n", 'b');
	printf("%% for %%\n");
	return (0);
}
