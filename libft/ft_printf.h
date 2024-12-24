/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 01:37:34 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/12 01:39:54 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_format(const char format, va_list *args);
int	ft_putadr(unsigned long ptr);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putnbrhex(unsigned long n, char c);
int	ft_putstr(char *s);
int	ft_putusnbr(unsigned int n);
int	ft_printf(const char *vstr, ...);
#endif
