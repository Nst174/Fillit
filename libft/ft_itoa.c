/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:20:52 by jcremin           #+#    #+#             */
/*   Updated: 2019/02/21 12:32:41 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_number(int num)
{
	int	b;

	b = 0;
	if (num <= 0)
	{
		num = num * (-1);
		b++;
	}
	while (num != 0)
	{
		b++;
		num = num / 10;
	}
	return (b);
}

char		*ft_itoa(int n)
{
	char	*string;
	int		j;
	int		s;

	j = ft_count_number(n);
	s = ft_count_number(n);
	if (!(string = (char *)malloc(sizeof(char) * (ft_count_number(n) + 1))))
		return (NULL);
	if (n == -0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		string[0] = '-';
		n = n * (-1);
	}
	while (n != 0)
	{
		string[--j] = (n % 10) + '0';
		n = n / 10;
	}
	string[s] = '\0';
	return (string);
}
