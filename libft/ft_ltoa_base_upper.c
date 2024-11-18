/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:21:24 by anebbou           #+#    #+#             */
/*   Updated: 2024/11/18 14:33:46 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_ltoa_base_upper(unsigned long n, int base, int is_upper)
{
	char			*digits;
	char			*result;
	int				len;
	unsigned long	temp;

	if (is_upper > 0)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	temp = n;
	len = 1;
	while (temp >= (unsigned long)base)
	{
		temp /= base;
		len++;
	}
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (len > 0)
	{
		result[--len] = digits[n % base];
		n /= base;
	}
	return (result);
}
