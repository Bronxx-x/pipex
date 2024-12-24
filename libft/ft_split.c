/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:54:53 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/06 22:45:29 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (words);
}

static char	**fsplit(char **ss, char *s, char c, int nwords)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (k < nwords)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		ss[k] = ft_substr(s, j, i - j);
		if (!ss[k])
		{
			while (k > 0)
				free(ss[--k]);
			free(ss);
			return (NULL);
		}
		k++;
	}
	ss[k] = NULL;
	return (ss);
}

char	**ft_split(const char *s, char c)
{
	char	**ss;
	int		nwords;
	char	**sf;

	if (!s)
		return (NULL);
	nwords = words((char *)s, c);
	ss = (char **)malloc((nwords + 1) * sizeof(char *));
	if (!ss)
		return (NULL);
	sf = fsplit(ss, (char *)s, c, nwords);
	if (!sf)
		return (NULL);
	return (sf);
}
