/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:35:36 by anebbou           #+#    #+#             */
/*   Updated: 2024/11/12 10:50:28 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

//convert integer to string - free after use
char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	len = count_digits(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = '0' + sign * (n % 10);
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
