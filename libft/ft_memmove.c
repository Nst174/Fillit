/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:53:10 by jcremin           #+#    #+#             */
/*   Updated: 2018/12/08 22:33:36 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;
	size_t	i;

	i = -1;
	dst1 = (char*)dst;
	src1 = (char*)src;
	if (src1 < dst1)
		while ((int)(--len) >= 0)
			*(dst1 + len) = *(src1 + len);
	else
		while (++i < len)
			*(dst1 + i) = *(src1 + i);
	return (dst);
}
