/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:11:57 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/09 02:39:19 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ssize(long int i, int sign)
{
	int	size;

	size = 0;
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	return (size + sign);
}

char	*iitoa(long int n, int size, char *num, int sign)
{
	int	i;

	i = size - 1;
	while (n > 0)
	{
		num[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (sign)
		num[0] = '-';
	num[size] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	char		*num;
	int			sign;
	int			size;
	long int	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = n;
	if (i == 0)
		return (ft_strdup("0"));
	sign = 0;
	if (i <= 0)
	{
		i *= -1;
		sign++;
	}
	size = ssize(i, sign);
	num = (char *)malloc((1 + size) * sizeof(char));
	if (!num)
		return (NULL);
	num = iitoa(i, size, num, sign);
	if (!num)
		return (NULL);
	return (num);
}
