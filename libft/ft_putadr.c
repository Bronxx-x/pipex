/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 02:21:02 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/12 04:47:08 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	len = ft_putnbrhex(ptr, 'x');
	return (len + 2);
}
