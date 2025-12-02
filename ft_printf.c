/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giborges <giborges@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:28:14 by giborges          #+#    #+#             */
/*   Updated: 2025/12/02 17:26:26 by giborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_base(unsigned long n, int base, int upper)
{
	char	*digits;
	char	buf[65];
	int		i;
	int		len;

	digits = "0123456789abcdef";
	if (upper)
		digits = "0123456789ABCDEF";
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

int	ft_print_int(long n)
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

int	ft_strspec(char c, va_list args)
{
	char	*s;
	int		len;

	len = 0;
	if (c == 'c')
	{
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	}
	if (c == 's')
	{
		s = va_arg(args, char *);
		if (!s)
			s = "(null)";
		ft_putstr_fd(s, 1);
		while (s[len])
			len++;
		return (len);
	}
	return (0);
}

int	ft_numspec(char c, va_list args)
{
	unsigned int long	ptr;

	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_base(va_arg(args, unsigned int), 10, 0));
	if (c == 'x' || c == 'X')
		return (ft_print_base(va_arg(args, unsigned int), 16, c == 'X'));
	if (c == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (!ptr)
		{
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		ft_putstr_fd("0x", 1);
		return (2 + ft_print_base(ptr, 16, 0));
	}
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
		{
			i++;
			if (format[i] == '%')
			{
				ft_putchar_fd('%', 1);
				count++;
			}
			else
				count += ft_organize(format[i], args);
		}
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
