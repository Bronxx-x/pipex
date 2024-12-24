/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:54:47 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/10 23:09:21 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n;
	t_list	*r;

	r = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		n = ft_lstnew(f(lst->content));
		if (n == NULL)
		{
			ft_lstclear(&n, del);
			return (NULL);
		}
		ft_lstadd_back(&r, n);
		lst = lst->next;
	}
	return (r);
}
