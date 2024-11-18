/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:25:49 by anebbou           #+#    #+#             */
/*   Updated: 2024/11/18 14:16:29 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_numbers(char specifier, va_list args)
{
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

int	ft_printf_int(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	ft_printf_uint(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_ltoa_base((unsigned long)n, 10);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	ft_printf_hex(unsigned int n, int is_upper)
{
	char	*str;
	int		len;

	str = ft_ltoa_base_upper((unsigned long)n, 16, is_upper);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	ft_printf_ptr(void *ptr)
{
	char	*str;
	int		len;

	len = 0;
	if (ptr == NULL)
	{
		len = write(1, "(nil)", 5);
	}
	else
	{
		str = ft_ltoa_base_upper((unsigned long)ptr, 16, 0);
		if (str == NULL)
			return (-1);
		len += write(1, "0x", 2);
		ft_putstr_fd(str, 1);
		len += ft_strlen(str);
		free(str);
	}
	return (len);
}
