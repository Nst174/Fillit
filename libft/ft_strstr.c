/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:32:49 by jcremin           #+#    #+#             */
/*   Updated: 2019/02/22 17:40:42 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(const char *hay, const char *needle)
{
	int		i;
	int		j;
	char	*str1;

	i = 0;
	j = 0;
	str1 = (char*)hay;
	if (needle[j] == '\0')
		return (&str1[i]);
	while (str1[i] != '\0')
	{
		while (str1[i + j] == needle[j])
		{
			if ((str1[i + j] == needle[j]) && needle[j + 1] == '\0')
				return (str1 + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
