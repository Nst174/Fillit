/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 03:03:35 by jcremin           #+#    #+#             */
/*   Updated: 2019/02/22 17:42:50 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	int		i;
	int		j;
	char	*str1;
	size_t	len1;

	i = 0;
	j = 0;
	len1 = len;
	str1 = (char*)hay;
	if (need[j] == '\0')
		return (&str1[i]);
	while (str1[i] != '\0' && len1)
	{
		while (str1[i + j] == need[j] && len1)
		{
			if ((str1[i + j] == need[j]) && need[j + 1] == '\0')
				return (str1 + i);
			j++;
			len1--;
		}
		i++;
		j = 0;
		len1 = len - i;
	}
	return (NULL);
}
