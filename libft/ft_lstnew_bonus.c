/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 01:07:39 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/10 02:13:36 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nnew;

	nnew = (t_list *)malloc(sizeof(t_list));
	if (!nnew)
		return (NULL);
	nnew->content = content;
	nnew->next = NULL;
	return (nnew);
}
