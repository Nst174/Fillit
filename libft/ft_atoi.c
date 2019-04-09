/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:32:36 by jcremin           #+#    #+#             */
/*   Updated: 2019/01/12 14:03:23 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_atoi(const char *str)
{
	unsigned long long	n;
	int					i;

	n = 0;
	i = 1;
	while (*str == '\r' || *str == '\t' || *str == '\n' ||
*str == '\v' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' && (*(str + 1) != '-'))
	{
		str++;
	}
	if (*str == '-')
	{
		i = -i;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		n = 10 * n + (*str - '0');
		str++;
	}
	if (n > 9223372036854775807)
		return ((i == 1) ? -1 : 0);
	return ((int)n * i);
}
