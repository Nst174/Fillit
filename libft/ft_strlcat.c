/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:12:39 by jcremin           #+#    #+#             */
/*   Updated: 2019/02/22 17:38:11 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (size > 0)
	{
		while (dst[i] && i < size)
			i++;
		j = i;
		while (src[i - j] && i < size - 1)
		{
			dst[i] = src[i - j];
			i++;
		}
		if (j < size)
			dst[i] = '\0';
		i = 0;
	}
	while (src[i] != '\0')
		i++;
	return (j + i);
}
