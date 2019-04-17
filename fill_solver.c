/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:44:59 by jcremin           #+#    #+#             */
/*   Updated: 2019/04/17 12:38:02 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void write_f_f(char **final_f, t_fill *lists, int a, int b, int g)
{
    int h;
	t_fill *k;
	char **temp;

	write(1, "WFF-1\n", 6);
    k = lists;
    h = 0;
    while (k->field[0][h] == '.')
	{
		write(1, "WFF-2\n", 6);
        h++;
	}
    if (h > 0)
    {
		write(1, "WFF-3\n", 6);
		 write_f_f_two(final_f, lists, a, b, g, h);
    }
    else
    {
		write(1, "WFF-4\n", 6);
        write_f_f_one(final_f, lists, a, b, g);
    }
}

int		itap(char **final_f, t_fill *lists, int a, int b, int g)
{
	int h;
	t_fill *k;

	k = lists;
	h = 0;
	while (k->field[0][h] == '.')
		h++;
	if (h > 0)
	{
		if (itap_two(final_f, k, a, b, g, h) == 1)
		{
			//write_f_f(final_f, k, a, b, g);
			//itap(final_f, k->next, g, h_f);
			return(1);
		}
		else 
		{
			//fff(final_f, g);
			return(0);
		}
	}
	else
	{
		if (itap_one(final_f, k, a, b, g) == 1)
        {
			//write_f_f(final_f, k, a, b, g);
            //itap(final_f, k->next, g, h_f);
			return(1);
		}
		else
		{
			//fff(final_f, g);
            return(0);
		}
	}
	return(1);
}
/*
**
*/
int where_coord(char **final_f, t_fill *lists, int g, int h_f)
{
	int a;
	int b;
	t_fill *k;

	a = 0;
	b = 0;
	k = lists;
	write(1, "where\n", 6);
	while (b < g)
	{
		//if (k == NULL)
		//return(1);
		
		while (final_f[b][a] != '\0')
		{
			if (final_f[b][a] == '.')
			{
				if (itap(final_f, k, a, b, g) == 1)
				{
					write(1, "----------", 10);
					write_f_f(final_f, k, a, b, g);
					print3(final_f, g);
					write(1, "where-1\n", 8);
					if (k->next != NULL)
					{
						if (where_coord(final_f, k->next, g, h_f) == 0)
						{
						write(1, "where-3\n", 8);
						fff(final_f, g, k->letter);
						a++;
						}
						else
							return (1);
					}
					else
						return (1);
					//return(1);
				}	
				else 
					a++;
			}
			else
				a++;
		}
		a = 0;
		b++;
		if (b == g && k->letter == 'A' + h_f)
		{
			write(1, "b == 0\n", 7);
			return (1);
		}
	}
	return (0);
}
/*
**
*/
char **field_in_final_f(char **final_f, t_fill *lists, int h_f, int g)
{
	t_fill *k;
	int    f;
	char **finish_f;
	int gg;
	//printf("%d", 2);
	//f = h_f;
	gg = g;
	finish_f = final_f;
	f = 1;
	k = lists;
	while (where_coord(finish_f, lists, gg, h_f) == 0)
	{
		write(1, "FIFF\n", 5);
		gg++;
		finish_f = create_final_f(gg);
		//print3(finish_f, gg);
		/*
		where_coord(final_f, lists, g);
		f--;
		*/
	}
	//print3(finish_f, gg);
	return(finish_f);
}
/*
**создаем итоговый массив и выделяем под него память
*/
char **create_final_f(int a)
{
	char **final_f;
	int i;
	int j;
	int k;

	//printf("%d", 1);
	k = a;
	//printf("%d", k);
	j = 0;
	i = 0;
	//ft_putnbr(k);
	final_f = (char **)malloc(sizeof(char *) * k);
	while (j < k)
	{
		final_f[j] = (char *)malloc(sizeof(char ) * (k + 1));
		j++;
	}
	i = 0;
	j = 0;
	while (j < k) 
	{
		while (i < k)
		{
			final_f[j][i] = '.';
			i++;
		}
		if (i == k)
		{
			write(1, "CFF\n", 4);
			final_f[j][i] = '\0';
		}
		j++;
		i = 0;
	}
	return (final_f);
}
