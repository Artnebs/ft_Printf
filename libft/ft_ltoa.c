/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:38:09 by anebbou           #+#    #+#             */
/*   Updated: 2024/11/18 14:17:27 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ltoa_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_fill_ltoa(char *str, long n, int len)
{
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (--len >= 0 && n != 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (n == 0 && len > 0)
		str[--len] = '0';
}

char	*ft_ltoa(long n)
{
	int		len;
	char	*str;

	len = ft_ltoa_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	else
		ft_fill_ltoa(str, n, len);
	return (str);
}
