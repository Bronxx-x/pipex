/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:00:02 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/15 01:07:24 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft1_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft1_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*st;

	j = 0;
	i = 0;
	if (!s1)
		s1 = ft1_calloc(1, 1);
	if (!s1 && !s2)
		return (NULL);
	st = (char *)malloc(ft1_strlen(s1) + ft1_strlen(s2) + 1);
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
	st[i + j] = '\0';
	return (free(s1), free(s2), st);
}

char	*ft1_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

void	ft1_bzero(void *s, size_t n)
{
	size_t		i;
	char		*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft1_calloc(size_t n, size_t size)
{
	char	*p;

	if (n && size > SIZE_MAX / n)
		return (NULL);
	p = (void *)malloc(n * size);
	if (p == NULL)
		return (NULL);
	ft1_bzero(p, n * size);
	return (p);
}
