/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:05:05 by jcremin           #+#    #+#             */
/*   Updated: 2019/02/21 15:33:06 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lst_new;
	t_list *lst2;

	if (!lst)
		return (NULL);
	lst2 = f(lst);
	lst_new = lst2;
	while (lst->next)
	{
		lst = lst->next;
		if (!(lst2->next = f(lst)))
		{
			free(lst2->next);
			return (NULL);
		}
		lst2 = lst2->next;
	}
	return (lst_new);
}
