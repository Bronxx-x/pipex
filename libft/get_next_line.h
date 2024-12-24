/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 04:23:39 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/14 04:33:58 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft1_strjoin(char *s1, char *s2);
int		ft1_strlen(const char *str);
char	*ft1_strchr(char *s);
char	*get_next_line(int fd);
void	*ft1_calloc(size_t n, size_t size);
void	ft1_bzero(void *s, size_t n);

#endif
