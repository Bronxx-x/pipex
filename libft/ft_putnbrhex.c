/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 02:21:27 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/12 04:28:50 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhex(unsigned long n, char c)
{
	int		len;
	char	*str;

	len = 0;
	if (c == 'x')
		str = "0123456789abcdef";
	if (c == 'X')
		str = "0123456789ABCDEF";
	if (n >= 16)
		len = ft_putnbrhex(n / 16, c);
	len++;
	ft_putchar(str[n % 16]);
	return (len);
}
