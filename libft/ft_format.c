/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 02:20:42 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/12 03:02:54 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char type, va_list *vargs)
{
	if (type == 'c')
		return (ft_putchar((char)va_arg(*vargs, int)));
	else if (type == 'u')
		return (ft_putusnbr(va_arg(*vargs, unsigned int)));
	else if ((type == 'i') || (type == 'd'))
		return (ft_putnbr(va_arg(*vargs, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(*vargs, char *)));
	else if (type == 'x' || type == 'X')
		return (ft_putnbrhex(va_arg(*vargs, unsigned int), type));
	else if (type == 'p')
		return (ft_putadr((unsigned long)va_arg(*vargs, void *)));
	else if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}
