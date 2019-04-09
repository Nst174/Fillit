/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 22:10:25 by jcremin           #+#    #+#             */
/*   Updated: 2019/01/12 16:07:45 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			z;

	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	z = 0;
	if (n == 0)
		return (NULL);
	while (z < n)
	{
		str1[z] = str2[z];
		if (str1[z] == (unsigned char)c)
			return (str1 + z + 1);
		z++;
	}
	return (NULL);
}
