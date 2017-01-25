/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:44:55 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/24 20:08:08 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 5000

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_arg
{
	char			conver;
	int				befor_flag;
	int				flag;
	int				len;
	int				len2;
	char 			*rebuffer;
	char			buffer[BUFF_SIZE];
	char			nbr[BUFF_SIZE];
	char			nbr2[BUFF_SIZE];
	int				precis;
	int				weidth;
	int				boul;
}					t_arg;

char				*ft_get_base_2(long nb, int base, char c, t_arg *proto);
t_arg 				*ft_space(t_arg *proto, va_list ap);
t_arg 				*ft_plus(t_arg *proto, va_list ap);
t_arg 				*ft_diese(t_arg *proto, va_list ap);
t_arg				*ft_travaille(t_arg *proto, va_list ap);
char				*ft_get_unsigned_base(unsigned long nb, int base, char c);
int					ft_preci(char format, char format2);
char				ft_conv(const char *format);
char				ft_return(const char *format);
int					ft_verif_flagg(char format, char format2, t_arg *proto);
int					ft_verif_befor(char format, t_arg *proto);
int					ft_check_last(char format);
int					ft_verif_last(const char *format);
char				*ft_yolo(t_arg *proto, va_list ap);
char				*ft_get_base(long nb, int base, char c);
int					ft_printf(const char *format, ...);
#endif
