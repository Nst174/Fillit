/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:41:42 by jcremin           #+#    #+#             */
/*   Updated: 2019/04/17 13:05:49 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	write_f_f_one(char **final_f, t_fill *p, int a, int b, int g)
{
	int i;
    int j;
    t_fill *k;

    i = 0;
    j = 0;
    k = p;
    while (j < 4)
    {
        while (k->field[j][i] != '\0')
        {
            if (k->field[j][i] != '.')
                if (final_f[b + j][a + i] == '.')
                    final_f[b + j][a + i] = k->field[j][i];
            i++;
        }
        i = 0;
        j++;
    }
}

void	write_f_f_two(char **final_f, t_fill *p, int a, int b, int g, int h)
{
    int i;
    int j;
    t_fill *k;


    i = 0;
    j = 0;
    k = p;
    while (j < 4)
    {
		while (k->field[j][i] != '\0')
		{
            if (k->field[j][i] != '.')
				if (final_f[b + j][a + i - h] == '.')
					final_f[b + j][a + i - h] = k->field[j][i];
            i++;
		}
        i = 0;
		j++;
    }
}
