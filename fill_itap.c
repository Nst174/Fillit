/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_itap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:45:33 by jcremin           #+#    #+#             */
/*   Updated: 2019/04/17 13:08:00 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	itap_one(char **final_f, t_fill *lists, int a, int b, int g)
{
	int i;
	int j;
	t_fill *k;

	k = lists;
    i = 0;
    j = 0;
	while (j < 4)
    {
        while (k->field[j][i] != '\0')
        {
            if (k->field[j][i] != '.')
            {
                if (((a + i) >= g) || ((b + j) >= g))
                {
                    return (0);
                }
                if (final_f[b + j][a + i] == '.')
                {
                    write(1, "-2\n", 3);
                }
                else
                {
                    write(1, "-3\n", 3);
                    return (0);
                }
            }
            i++;
        }
        i = 0;
        j++;
    }
    return (1);
}

int	itap_two(char **final_f, t_fill *lists, int a, int b, int g, int h)
{
	int i;
	int j;
	t_fill *k;

	write(1, "ITAP-2\n", 7);
	k = lists;
	i = 0;
	j = 0;
	while (j < 4)
    {
		 write(1, "1", 1);
        while (k->field[j][i] != '\0')
        {
			 write(1, "2", 1);
            if (k->field[j][i] != '.')
            {
				  write(1, "3", 1);
                if (((a + i - h) >= g) || ((b + j) >= g))
                {
					 write(1, "-1\n", 3);
                    //write(1, " return 0 \n", 11);
                    return (0);
                }
				 write(1, "4", 1);
                if (final_f[b + j][a + i - h] == '.')
                {
					write(1, "-2\n", 3);
                    //write(1, "5", 1);
                }
                else
                {
					write(1, "-3\n", 3);
                    //write(1, " return 0 \n", 11);
                    return (0);
                }
            }
            i++;
        }
        i = 0;
        j++;
    }
	 write(1, "-4\n", 3);
    //write(1, " return 1 \n", 11);
    return (1);
}
