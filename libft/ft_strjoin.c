/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:03:53 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/06 17:35:27 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{	
	size_t	i;
	size_t	j;
	char	*st;

	j = 0;
	i = 0;
	st = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (st == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		st[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		st[i + j] = s2[j];
		j++;
	}
	st [i + j] = '\0';
	return (st);
}
