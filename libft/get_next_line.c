/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 00:59:00 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/15 05:10:50 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rem(char *buf, char *l)
{
	int		i;
	int		j;
	char	*rem;

	i = ft1_strlen(l);
	j = 0;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	while (buf[i++])
		j++;
	rem = ft1_calloc((j + 1), 1);
	i = ft1_strlen(l);
	j = 0;
	while (buf[i + j])
	{
		rem[j] = buf[i + j];
		j++;
	}
	rem[j] = '\0';
	return (free(buf), rem);
}

char	*ft_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	line = ft1_calloc(i + 2, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*readf(int fd, char *buf)
{
	char	*bufch;
	int		bread;

	bread = 1;
	while (bread > 0 && !ft1_strchr(buf))
	{
		bufch = ft1_calloc(BUFFER_SIZE + 1, 1);
		if (!bufch)
			return (NULL);
		bread = (int)read(fd, bufch, BUFFER_SIZE);
		if (bread == -1 || (!buf && bread == 0))
		{
			free(bufch);
			return (NULL);
		}
		bufch[bread] = '\0';
		buf = ft1_strjoin(buf, bufch);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = readf(fd, buf);
	if (!tmp)
	{
		if (buf)
			free(buf);
		buf = NULL;
		return (NULL);
	}
	buf = tmp;
	line = ft_line(buf);
	buf = ft_rem(buf, line);
	return (line);
}
