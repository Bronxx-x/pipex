/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:18:53 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/05 21:01:46 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1 [i] != '\0' && i < len)
	{
		j = 0;
		while (j + i < len && s1 [i + j] != '\0' && s2 [j] != '\0'
			&& s1 [i + j] == s2 [j])
		{
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)(s1 + i));
		i++;
	}
	return (0);
}
