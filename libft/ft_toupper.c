/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 05:28:19 by jcremin           #+#    #+#             */
/*   Updated: 2018/12/09 05:32:31 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int c)
{
	char i;

	i = (char)c;
	if (c >= 'a' && c <= 'z')
		return ((int)(c - 32));
	return ((int)c);
}
