/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:09:52 by jcremin           #+#    #+#             */
/*   Updated: 2019/02/21 12:34:01 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static char	*ft_count_letters(char const *s, char c, int *a)
{
	char	*string;
	int		i;

	if (!(string = (char *)malloc(sizeof(string) * (ft_strlen(s)))))
		return (NULL);
	i = 0;
	while (s[*a] != c && s[*a])
	{
		string[i] = s[*a];
		i++;
		*a += 1;
	}
	string[i] = '\0';
	while (s[*a] == c && s[*a])
		*a += 1;
	return (string);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**mass;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_count_words(s, c);
	if (!(mass = (char **)malloc(sizeof(char *) * (len + 2))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < len && s[i])
	{
		mass[j] = ft_count_letters(s, c, &i);
		j++;
	}
	mass[j] = NULL;
	return (mass);
}
