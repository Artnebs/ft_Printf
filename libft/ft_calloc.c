/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:59:41 by anebbou           #+#    #+#             */
/*   Updated: 2024/11/12 10:15:46 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>
// Allocates memory and initializes all bits to zero. free after use
void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	unsigned char	*ptr;
	size_t			i;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	i = 0;
	total_size = count * size;
	ptr = (unsigned char *)malloc(total_size);
	if (!ptr)
		return (NULL);
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
