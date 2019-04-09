/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:31:01 by jcremin           #+#    #+#             */
/*   Updated: 2019/01/12 15:58:49 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char *s1;
	char *s2;
	char symb;

	s1 = (char *)s;
	s2 = 0;
	symb = (char)c;
	if (c == '\0')
	{
		while (*s1)
			s1++;
		return (s1);
	}
	while (*s1 != '\0')
	{
		if (*s1 == symb)
		{
			s2 = s1;
		}
		s1++;
	}
	if (s2 != 0)
		return (s2);
	return (NULL);
}
