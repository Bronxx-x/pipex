/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:38:47 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/06 18:51:00 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*st;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strrchr(set, s1[end - 1]) && end > start)
		end--;
	st = (char *)malloc(end - start + 1);
	if (!st)
		return (NULL);
	ft_strlcpy(st, s1 + start, end - start + 1);
	return (st);
}
