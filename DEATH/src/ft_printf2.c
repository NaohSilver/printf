/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 02:57:05 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/05 06:45:46 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
static int ft_verif_last_conv(char *format)
{
	if (*format == 's' || *format == 'S' || *format == 'p' || *format == 'd' ||
	*format == 'D' || *format == 'i' || *format == 'o' || *format == 'O' ||
	*format == 'u' || *format == 'U' || *format == 'x' || *format == 'X' ||
	*format == 'c' || *format == 'C')
		return (1);
	else
		return (0);
}

static char *ft_print_z(char *str, va_list *ap, t_arg *arg)
{
	static char *z = NULL;

	if (arg->force_prefix == 1 && )
		(ft_putstr("0x"));

}

static char *ft_yolo_formatage(char *str, va_list *ap, t_arg *arg)
{
	int len;

	len = ft_strlen(str);
	if (str[len - 1] == 'z')
		return (ft_print_z(str, ap, arg))
	else
		return (NULL);
}

static int ft_handle(char *format, va_list *ap, t_arg *arg, char *str)
{
	int i;
	static char *str2 = NULL;

	i = 0;
	while (*format++ && ft_verif_last_conv(format) != 1)
	{
		str[i] == *format;
		i++;
	}
	str2 = ft_yolo_formatage(str, ap, arg);
	len = ft_strlen(str);
	return (len);
}*/

static void	ft_putnstr_fd(char const *str, size_t str_len)
{
	write(1, str, str_len);
}

static void	ft_putnstr(char const *str, size_t str_len)
{
	ft_putnstr_fd(str, str_len);
}

static char	*ft_preci(char **format, va_list *list, t_arg *arg)
{
	int prec;

	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			if ((prec = va_arg(*list, int)) >= 0)
			{
				arg->got_precision = 1;
				arg->precision = prec;
			}
			return (*format);
		}
		else
		{
			while (ft_isdigit(**format))
				arg->precision = arg->precision * 10 + (*(*format)++ - '0');
			arg->got_precision = 1;
			return (*format);
		}
	}
	else
		return (*format);
}

static char	*ft_length(char **format, t_arg *arg)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		arg->length = hh;
		return (*format += 2);
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		arg->length = ll;
		return (*format += 2);
	}
	else if (**format == 'h' || **format == 'l' || **format == 'j' ||
					**format == 'z')
	{
		if (**format == 'h')
			arg->length = h;
		else if (**format == 'l')
			arg->length = l;
		else if (**format == 'j')
			arg->length = j;
		else if (**format == 'z')
			arg->length = z;
		return ((*format)++);
	}
	else
		return (*format);
}

static char	*ft_width(char **format, va_list *list, t_arg *arg)
{
	int	got;

	arg->width = 0;
	while (**format == '.' || ft_isdigit(**format))
	{
		if (**format == '.')
		{
			(*format)++;
			got = va_arg(*list, int);
			if (got < 0)
				arg->right_pad = 1;
			arg->width = got < 0 ? -got : got;
			arg->got_width = 1;
		}
		if (ft_isdigit(**format))
		{
			arg->got_width = 1;
			arg->width = 0;
			while (ft_isdigit(**format))
				arg->width = arg->width * 10 + (*(*format)++ - '0');
		}
	}
	return (*format);
}

static char	*ft_flags(char **format, t_arg *arg)
{
	if (**format == '#' || **format == '0' || **format == '-' || **format == '+'
		|| **format == ' ')
	{
		if (**format == '#')
			arg->force_prefix = 1;
		else if (**format == '0')
			arg->pad_zeroes = 1;
		else if (**format == '-')
			arg->right_pad = 1;
		else if (**format == '+')
			arg->force_sign = 1;
		else if (**format == ' ')
			arg->blank_sign = 1;
		(*format)++;
		if (arg->right_pad)
		{
			arg->pad_zeroes = 0;
			return (ft_flags(format, arg));
		}
		else
			return (ft_flags(format, arg));
	}
	else
		return (*format);
}

static int	ft_recup(char **format, va_list *ap, t_arg *arg)
{
	int		res;

	if (**format == '\0'
		|| (*(++*format)) == '\0')
		return (0);
	else if (ft_flags(format, arg) == NULL
		|| ft_width(format, ap, arg) == NULL
		|| ft_preci(format, ap, arg) == NULL
		|| ft_length(format, arg) == NULL)
		return (-1);
/*	res = ft_handle(format, ap, arg, str);*/
	ft_putnbr(arg->force_prefix);
	ft_putchar('\n');
	ft_putnbr(arg->pad_zeroes);
	ft_putchar('\n');
	ft_putnbr(arg->right_pad);
	ft_putchar('\n');
	ft_putnbr(arg->force_sign);
	ft_putchar('\n');
	ft_putnbr(arg->blank_sign);
	ft_putchar('\n');
	ft_putnbr(arg->got_width);
	ft_putchar('\n');
	ft_putnbr(arg->width);
	ft_putchar('\n');
	ft_putnbr(arg->right_pad);
	ft_putchar('\n');
	ft_putnbr(arg->pad_zeroes);
	ft_putchar('\n');
	ft_putnbr(arg->got_precision);
	ft_putchar('\n');
	ft_putnbr(arg->precision);
	(*format)++;
	return (res);
}

static int		ft_epic_printf(const char *format, va_list *ap, int chr)
{
	char		*next;
	t_arg		arg;
	int		len;

	next = ft_strchr(format, '%');
	if (*format == '\0')
		return (chr);
	else if (next == NULL)
	{
		ft_putstr(format);
		return (chr + ft_strlen(format));
	}
	else if (next > format)
	{
		ft_putnstr(format, next - format);
		return (ft_epic_printf(next, ap, chr + (next - format)));
	}
	else
	{
		ft_bzero(&arg, sizeof(arg));
		if ((len = ft_recup((char **)&format, ap, &arg)) - 1)
			return (-1);
		else
			return (ft_epic_printf(format, ap, chr + len));
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			get_print;

	va_start(ap, format);
	get_print = ft_epic_printf(format, &ap, 0);
	va_end(ap);
	return (get_print);
}
