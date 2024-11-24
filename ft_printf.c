/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:25:49 by anebbou           #+#    #+#             */
/*   Updated: 2024/11/20 17:59:04 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_handle_conversion(*format, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

int	ft_handle_conversion(char specifier, va_list args)
{
	if (specifier == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if (specifier == 'c')
		return (ft_printf_char(va_arg(args, int)));
	if (specifier == 's')
		return (ft_printf_str(va_arg(args, char *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_printf_int(va_arg(args, int)));
	if (specifier == 'u')
		return (ft_printf_uint(va_arg(args, unsigned int)));
	if (specifier == 'x' || specifier == 'X')
		return (ft_printf_hex(va_arg(args, unsigned int), specifier == 'X'));
	if (specifier == 'p')
		return (ft_printf_ptr(va_arg(args, void *)));
	return (0);
}
