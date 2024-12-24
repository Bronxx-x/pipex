/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 23:10:41 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/05 23:27:42 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*p;

	p = (void *)malloc (n * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, n * size);
	return (p);
}
