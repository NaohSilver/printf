/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 07:53:35 by niludwig          #+#    #+#             */
/*   Updated: 2017/01/10 01:51:49 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int ft_verif_last_conv(const char *format)
{
	if (*format == 's' || *format == 'S' || *format == 'p' || *format == 'd' ||
	*format == 'D' || *format == 'i' || *format == 'o' || *format == 'O' ||
	*format == 'u' || *format == 'U' || *format == 'x' || *format == 'X' ||
	*format == 'c' || *format == 'C')
		return (1);
	else
		return (0);
}

static int ft_verif_flagg(const char *format)
{
	if (*format == 'l' && *format++ == 'l')
		return (1);
	else if (*format == 'h' && *format++ == 'h')
		return (2);
	else if (*format == 'j')
		return (3);
	else if (*format == 'l')
		return (4);
	else if (*format == 'h')
		return (5);
	else if (*format == 'z')
		return (6);
	else
		return (0);
}

static int ft_after_flagg(const char *format)
{
	++format;
	if (*format++ == )
	if (*format == '')
		return (1);
	else
		return (0);
}

static int ft_verif_precis(const char *format)
{
	if (*format == '#')
		return (1);
	else if (*format == '+')
		return (2);
	else if (*format == '-')
		return (3);
	else if (*format == ' ')
		return (4);
	else
		return (0);
}

static int ft_useless(const char *format)
{
	if (*format == '%')
		return (1);
	return (0);
}

static char *ft_powa(const char *format, va_list ap)
{
	while (1 != ft_verif_last_conv(*format) && ++format)
	{
		if (1 == ft_verif_flagg(*format) && );
			return ()
	}
}

static	int		ft_chaine(const char **format)
{
	int i;

	i = 0;
	while (1 != ft_verif_last_conv(*format))
	{
		i++;
		*format++;
		if (i == 5000)
			return (0);
	}
	return (i);
}

static	int		ft_get_last(const char **format, va_list ap)
{
	int			len;
	char		*str = NULL;

	len = 0;
	str = ft_
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

static int ft_1(const char *format)
{
	if (*format == 's' || *format == 'd' || *format == 'D' || *format == 'o'
		|| *format == 'O' || *format == 'u' || *format == 'U' || *format == 'x'
		|| *format == 'X' || *format == 'b' || *format == 'B')//c
		return (1);
	else
		return (0);
}

static int ft_2(const char *format)
{
	if (*format++ == 'd' || *format++ == 'i')
		return (1);
	else if (*format == 'o')
		return (1);
	else if (*format == 'u')
		return (1);
	else if (*format == 'x')
		return (1);
	else if (*format == 'X')
		return (1);
	else if (*format == 'c')
		return (1);
	else if (*format == 's')
		return (1);
	else
		return (0);

}

/*static int ft_3(const char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		return (1);
	else if (*format == 'o')
		return (1);
	else if (*format == 'u')
		return (1);
	else if (*format == 'x')
		return (1);
	else if (*format == 'X')
		return (1);
	else
		return (0);
}*/

/*static int ft_4(const char *format, va_list ap) fait
{
	if (*format == 'd' || *format == 'i')
		return (1);
	else if (*format == 'o')
		return (1);
	else if (*format == 'u')
		return (1);
	else if (*format == 'x')
		return (1);
	else if (*format == 'X')
		return (1);
	else
		return (0);
}*/

static int ft_5(const char *format)
{
	if (*format++ == 'd' || *format++ == 'i')
		return (1);
	else if (*format == 'o')
		return (1);
	else if (*format == 'u')
		return (1);
	else if (*format == 'x')
		return (1);
	else if (*format == 'X')
		return (1);
	else
		return (0);
}

static int ft_6(const char *format)
{
	if (*format++ == 'd' || *format++ == 'i')
		return (1);
	else if (*format == 'o')
		return (1);
	else if (*format == 'u')
		return (1);
	else if (*format == 'x')
		return (1);
	else if (*format == 'X')
		return (1);
	else
		return (0);
}

static int ft_7(const char *format)
{
	if (*format++ == 'd' || *format++ == 'i')
		return (1);
	else if (*format == 'o')
		return (1);
	else if (*format == 'u')
		return (1);
	else if (*format == 'x')
		return (1);
	else if (*format == 'X')
		return (1);
	else
		return (0);
}

static char *ft_bool(int ap)
{
	char *content;

	if (ap == 1)
	{
		content = (char *)malloc(sizeof(char) * 5);
		content = "true";
		return (content);
	}
	else if (ap == 0)
	{
		content = (char *)malloc(sizeof(char) * 6);
		content = "false";
		return (content);
	}
	else
	{
		content = (char *)malloc(sizeof(char) * 12);
		content = "not boolean";
		return (content);
	}
}

static char *ft_yolo2(const char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		return (ft_get_base(va_arg(ap, long), 10, '.'));
	else if (*format == 'o')
		return (ft_get_base(va_arg(ap, unsigned long), 8, '.'));
	else if (*format == 'u')
		return (ft_get_base(va_arg(ap, unsigned long), 10, '.'));
	else if (*format == 'x')
		return (ft_get_base(va_arg(ap, unsigned long), 16, 'a'));
	else if (*format == 'X')
		return (ft_get_base(va_arg(ap, unsigned long), 16, 'A'));
//	else if (*format == 'c')
//		return ((char *)va_arg(ap, wint_t));
	else if (*format == 's')
		return ((char *)va_arg(ap, wchar_t *));
	else
		return (NULL);
}

/*static char *ft_yolo3(const char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		return (ft_get_base(va_arg(ap, short), 10, '.'));
	else if (*format == 'o')
		return (ft_get_base(va_arg(ap, unsigned short), 8, '.'));
	else if (*format == 'u')
		return (ft_get_base(va_arg(ap, unsigned short), 10, '.'));
	else if (*format == 'x')
		return (ft_get_base(va_arg(ap, unsigned short), 16, 'a'));
	else if (*format == 'X')
		return (ft_get_base(va_arg(ap, unsigned short), 16, 'A'));
	else
		return (NULL);
}*/

static char *ft_yolo6(const char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		return (ft_get_base(va_arg(ap, intmax_t), 10, '.'));
	else if (*format == 'o')
		return (ft_get_base(va_arg(ap, intmax_t), 8, '.'));
	else if (*format == 'u')
		return (ft_get_base(va_arg(ap, uintmax_t), 10, '.'));
	else if (*format == 'x')
		return (ft_get_base(va_arg(ap, uintmax_t), 16, 'a'));
	else if (*format == 'X')
		return (ft_get_base(va_arg(ap, uintmax_t), 16, 'A'));
	else
		return (NULL);
}

/*static char *ft_yolo4(const char *format, va_list ap) // a refair
{
	if (*format == 'd' || *format == 'i')
		return ((char *)ft_get_base(va_arg(ap, int), 10, '.'));
	else if (*format == 'o')
		return ((unsigned char *)ft_get_base(va_arg(ap, int), 8, '.'));
	else if (*format == 'u')
		return ((unsigned char *)ft_get_base(va_arg(ap, int), 10, '.'));
	else if (*format == 'x')
		return ((unsigned char *)ft_get_base(va_arg(ap, int), 16, 'a'));
	else if (*format == 'X')
		return ((unsigned char *)ft_get_base(va_arg(ap, int), 16, 'A'));
	else
		return (NULL);
}*/

static char *ft_yolo5(const char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		return (ft_get_base(va_arg(ap, long long), 10, '.'));
	else if (*format == 'o')
		return (ft_get_base(va_arg(ap, unsigned long long), 8, '.'));
	else if (*format == 'u')
		return (ft_get_base(va_arg(ap, unsigned long long), 10, '.'));
	else if (*format == 'x')
		return (ft_get_base(va_arg(ap, unsigned long long), 16, 'a'));
	else if (*format == 'X')
		return (ft_get_base(va_arg(ap, unsigned long long), 16, 'A'));
	else
		return (0);
}

static char *ft_yolo7(const char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		return (ft_get_base(va_arg(ap, size_t), 10, '.'));
	else if (*format == 'o')
		return (ft_get_base(va_arg(ap, size_t), 8, '.'));
	else if (*format == 'u')
		return (ft_get_base(va_arg(ap, size_t), 10, '.'));
	else if (*format == 'x')
		return (ft_get_base(va_arg(ap, size_t), 16, 'a'));
	else if (*format == 'X')
		return (ft_get_base(va_arg(ap, size_t), 16, 'A'));
	else
		return (0);
}

static	int		ft_find(const char **format)
{
	if (**format == 37)
	{
		ft_putchar(37);
		return (1);
	}
	else if (**format == '@')
	{
		ft_putchar('@');
		return (1);
	}
	else
		return (0);
}

/*static int ft_space(const char **format)
{
	if (**format == ' ')
	{
		ft_putchar(' ');
		return (1);
	}
	else
		return (0);
}*/

static	char	*ft_yolo(const char *format, va_list ap)
{
	if (*format == 's')
		return (va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		return (ft_get_base(va_arg(ap, int), 10, '.'));
	else if (*format == 'D')
		return (ft_get_base(va_arg(ap, long), 10, '.'));
	else if (*format == 'o')
		return (ft_get_base(va_arg(ap, int), 8, '.'));
	else if (*format == 'O')
		return (ft_get_base(va_arg(ap, long), 8, '.'));
	else if (*format == 'u')
		return (ft_get_base(va_arg(ap, unsigned int), 10, '.'));
	else if (*format == 'U')
		return (ft_get_base(va_arg(ap, unsigned long), 10, '.'));
	else if (*format == 'x')
		return (ft_get_base(va_arg(ap, unsigned int), 16, 'a'));
	else if (*format == 'X')
		return (ft_get_base(va_arg(ap, unsigned int), 16, 'A'));
	else if (*format == 'b')
		return (ft_get_base(va_arg(ap, int), 2, '.'));
	else if (*format == 'p')
		return (ft_strcat("0x", ft_get_base(va_arg(ap, unsigned long),
		 16, 'a')));
	else if (*format == 'B')
	 	return (ft_bool(va_arg(ap, int)));
	else
		return (NULL);
}

/*static int ft_get_h(const char **format, va_list ap) // probleme de short
{
	int len;
	char *str;

	len = 0;
	if (1 == ft_3(*format, ap))
		str = ft_yolo3(*format, ap);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}*/

/*static int ft_get_hh(const char **format, va_list ap) // probleme de char
{
	int len;
	char *str;

	len = 0;
	if (1 == ft_4(*format, ap))
		str = ft_yolo4(*format, ap);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}*/

static int ft_get_j(const char **format, va_list ap)
{
	int len;
	char *str = NULL;

	len = 0;
	if (1 == ft_6(*format))
		str = ft_yolo6(*format, ap);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

static int ft_get_l(const char **format, va_list ap)
{
	int len;
	char *str = NULL;

	len = 0;
	if (1 == ft_2(*format))
		str = ft_yolo2(*format, ap);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

static int ft_get_z(const char **format, va_list ap)
{
	int len;
	char *str = NULL;

	len = 0;
	if (1 == ft_7(*format))
		str = ft_yolo7(*format, ap);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

static int ft_get_ll(const char **format, va_list ap)
{
	int len;
	char *str = NULL;

	len = 0;
	if (1 == ft_5(*format))
		str = ft_yolo5(*format, ap);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

static char *ft_diet_d2(const char *format, va_list ap)
{
	if (*format == 'x')
	{
		ft_putchar('0');
		ft_putchar('x');
		return (ft_get_base(va_arg(ap, unsigned int), 16, 'a'));
	}
	else if (*format == 'X')
	{
		ft_putchar('0');
		ft_putchar('X');
		return (ft_get_base(va_arg(ap, unsigned int), 16, 'A'));
	}
	else
		return (0);
}

static char *ft_diet_d(const char *format, va_list ap)
{
	if (*format == 'o')
	{
		ft_putchar('0');
		return (ft_get_base(va_arg(ap, unsigned int), 8, '.'));
	}
	else if (*format == 'O')
	{
		ft_putchar('0');
		return (ft_get_base(va_arg(ap, unsigned long), 8, '.'));
	}
	else
		return (0);
}

static int ft_get_d2(const char **format, va_list ap)
{
	int			len;
	char		*str = NULL;

	len = 0;
	str = ft_diet_d2(*format, ap);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

static int ft_get_d(const char **format, va_list ap)
{
	int			len;
	char		*str = NULL;

	len = 0;
	str = ft_diet_d(*format, ap);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

static	int		ft_get_next_char(const char **format, va_list ap)
{
	int			len;
	char		*str = NULL;

	len = 0;
	if (1 == ft_1(*format))
		str = ft_yolo(*format, ap);
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			tmp;
	int			get_print;
	int			value;
	int 		i;

	i = 0;
	value = 0;
	get_print = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		while ((*format != '%' && *format) && ++get_print)
			ft_putchar(*format++);
		if (*format == '%' && ++format)
		{
			if (*format == ' ')
			{
				get_print++;
				ft_putchar(' ');
				format++;
			}
			if (1 == ft_find((&format)) && ++format)
				get_print++;
			/*else if (*format == '+')
			{
				format++;
				ft_yoloswag_power((&format), ap);
			}*/
			else if (*format == '#')
			{
				format++;
				while (*format == '0')
				{
					format++;
				}
				if (*format == 'x' || *format == 'X')
				{
					tmp = ft_get_d2((&format), ap);
					get_print++;
				}
				else if (*format == 'o' || *format == 'O')
					tmp = ft_get_d((&format), ap);
				format++;
				get_print++;
			}
			else if (*format == '0') // pas tout a fait
				format++;
			else if (*format == 'l')
			{
				format++;
				get_print++;
				if (*format == 'l')
				{
					format++;
					get_print++;
					tmp = ft_get_ll((&format), ap);
				}
				else
					tmp = ft_get_l((&format), ap);
				format++;
				get_print++;
			}
			else if (*format == 'j')
			{
				format++;
				get_print++;
				tmp = ft_get_j((&format), ap);
				format++;
				get_print++;
			}
			else if (*format == 'z')
			{
				format++;
				get_print++;
				tmp = ft_get_z((&format), ap);
				format++;
				get_print++;
			}
/*			else if (*format == 'h')
			{
				format++;
				get_print++;
				if (*format == 'h')
				{
					format++;
					get_print++;
					tmp = ft_get_hh((&format), ap);
				}
				else
				tmp = ft_get_h((&format), ap);
				format++;
				get_print++;
			}*/
			else
			{
				tmp = ft_get_next_char((&format), ap);
				format++;
				get_print += tmp;
			}
		}
	}
	va_end(ap);
	return (get_print);
}
