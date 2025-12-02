/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giborges <giborges@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:39:47 by giborges          #+#    #+#             */
/*   Updated: 2025/12/02 17:29:26 by giborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_organize(char c, va_list args)
{
	if (c == 'c' || c == 'C' || c == 's' || c == 'S')
		return (ft_strspec(c, args));
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (ft_numspec(c, args));
	return (0);
}
