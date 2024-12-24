/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 03:26:41 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/09 03:48:16 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*sf;
	unsigned int		i;
	unsigned int		l;

	l = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	sf = malloc(sizeof(char) * (l + 1));
	if (!sf)
		return (NULL);
	while (l > i)
	{
		sf[i] = (*f)(i, s[i]);
		i++;
	}
	sf[i] = '\0';
	return (sf);
}
