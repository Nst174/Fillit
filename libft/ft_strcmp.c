/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 02:52:00 by jcremin           #+#    #+#             */
/*   Updated: 2018/12/15 19:42:27 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *d1;
	unsigned char *d2;

	d1 = (unsigned char*)s1;
	d2 = (unsigned char*)s2;
	while (*d1 == *d2 && (*d1 != '\0' || *d2 != '\0'))
	{
		d1++;
		d2++;
	}
	return (*d1 - *d2);
}
