/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:04:38 by jcremin           #+#    #+#             */
/*   Updated: 2018/12/08 22:29:21 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_bzero(void *s, size_t n)
{
	char	*string;
	size_t	i;

	i = 0;
	string = (char*)s;
	while (i < n)
	{
		string[i] = '\0';
		i++;
	}
}
