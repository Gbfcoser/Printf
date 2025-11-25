/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giborges <giborges@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:28:14 by giborges          #+#    #+#             */
/*   Updated: 2025/11/24 11:14:55 by giborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_base(unsigned long n, int base, int upper)
{
	char	*digits;
	char	buf[65];
	int		i;
	int		len;

	digits = (upper ? "0123456789ABCDEF" : "0123456789abcdef");
	if (n == 0)
		return (ft_putchar_fd('0', 1), 1);
	i = 0;
	while (n > 0)
	{
		buf[i++] = digits[n % base];
		n /= base;
	}
	len = i;
	while (--i >= 0)
		ft_putchar_fd(buf[i], 1);
	return (len);
}

static int	ft_print_int(long n)
{
	int	count;

	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		count = 1;
	}
	else
		count = 0;
	return (count + ft_print_base((unsigned long)n, 10, 0));
}

static int	ft_spec(char c, va_list args)
{
	char	*s;

	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	if (c == 's')
	{
		s = va_arg(args, char *);
		if (!s)
			s = "(null)";
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_base(va_arg(args, unsigned int), 10, 0));
	if (c == 'x' || c == 'X')
		return (ft_print_base(va_arg(args, unsigned int), 16, c == 'X'));
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (2 + ft_print_base(va_arg(args, unsigned long), 16, 0));
	}
	if (c == '%')
		return (ft_putchar_fd('%', 1), 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count += ft_spec(format[++i], args);
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
