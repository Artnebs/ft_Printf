/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:11:38 by anebbou           #+#    #+#             */
/*   Updated: 2024/11/18 14:23:31 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Convert a long to a string in a specific base - free after use
char	*ft_ltoa_base(unsigned long n, int base)
{
	char			*digits;
	char			*str;
	int				len;
	unsigned long	temp;

	digits = "0123456789abcdef";
	len = 1;
	temp = n;
	while (temp >= (unsigned long)base)
	{
		temp /= base;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = digits[n % base];
		n /= base;
	}
	return (str);
}
