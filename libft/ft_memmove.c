/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 04:45:29 by yhamdan           #+#    #+#             */
/*   Updated: 2024/08/30 05:55:34 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (p2 > p1)
	{
		while (n-- > 0)
			p2[n] = p1[n];
	}
	else
		ft_memcpy(p2, p1, n);
	return (dest);
}
