/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 02:20:07 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/12 02:55:51 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *vstr, ...)
{
	va_list	varg;
	int		n;
	int		ch;

	va_start(varg, vstr);
	n = 0;
	ch = 0;
	while (*vstr)
	{
		if (*vstr == '%')
		{
			ch = ft_format(*(++vstr), &varg);
			if (ch == -1)
				return (-1);
			n += ch;
		}
		else
		{
			write(1, vstr, 1);
			n++;
		}
		vstr++;
	}
	va_end(varg);
	return (n);
}
