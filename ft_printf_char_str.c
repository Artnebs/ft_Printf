/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:32:23 by anebbou           #+#    #+#             */
/*   Updated: 2024/11/18 10:57:51 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char_str(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_printf_char(va_arg(args, int)));
	if (specifier == 's')
		return (ft_printf_str(va_arg(args, char *)));
	return (0);
}

int	ft_printf_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf_str(char *str)
{
	int len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}
