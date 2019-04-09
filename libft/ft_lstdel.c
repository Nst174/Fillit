/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:37:51 by jcremin           #+#    #+#             */
/*   Updated: 2019/02/21 13:53:34 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *lst2;

	lst = *alst;
	while (lst)
	{
		lst2 = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = lst2;
	}
	*alst = NULL;
}
