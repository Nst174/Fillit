/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:44:59 by jcremin           #+#    #+#             */
/*   Updated: 2019/04/09 14:05:51 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char **write_f_f(char **final_f, t_fill *p, int a, int b, int g)
{
	int i;
	int j;
	t_fill *k;


	// write(1, "HHHH\n", 5);
	i = 0;
	j = 0;
	k = p;
	while (j < g)
	{
		//write(1, "7", 1);
		while (k->field[j][i] != '\0')
		{
			//write(1, "8", 1);
			if (k->field[j][i] != '.')
			{
				//write(1, "9", 1);
				if (final_f[b + j][a + i] == '.')
				{
					//write(1, "+", 1);
					final_f[b + j][a + i] = k->field[j][i];
				}
			}
			i++;
		}
		i = 0;
		j++;
	}
	//write(1, "EEE\n", 4);
	return (final_f);
}

int itap(char **final_f, t_fill *lists, int a, int b, int g)
{
	int i;
	int j;
	t_fill *k;

	//write(1, "0", 1);
	k = lists;
	i = 0;
	j = 0;
	if (((a + i) > g) || ((b + j) > g))
    {
		//write(1, "return 0 \n", 10);
        return (0);
    }
	while (j < g)
	{
		//write(1, "1", 1);
		while (k->field[j][i] != '\0')
		{
			//write(1, "2", 1);
			if (k->field[j][i] != '.')
			{
				//write(1, "3", 1);
				if (final_f[b + j][a + i] == '.')
				{
					//write(1, "4", 1);
				}
				else
				{
					//write(1, "return 0 \n", 10);
					return (0);
				}
			}
				i++;
		}
		i = 0;
		j++;
	}
	//write(1, "return 1 \n", 10);
	return (1);
}
/*
**
*/
int where_coord(char **final_f, t_fill *lists, int g)
{
	int i;
	int j;
	int a;
	//int s;
	t_fill *k;

	k = lists;
	//printf("%d", 3);
	a = 0;
	i = 0;
	j = 0;
	//s = 0;
	while (k->next != NULL)//
		{
			//lists = k; //новая строка, может сломать весь алгоритм
			//write(1, "A", 1);
			while (j < g)
			{
				//write(1, "B", 1);
				while (i < g/*final_f[j][i] != '\0'*/)
				{
					//write(1, "C", 1);
					if (final_f[j][i] == '.' && (itap(final_f, k, i, j, g) == 1))
					{
						//write(1, "NNN\n", 4);
						write_f_f(final_f, k, i, j, g);
						k = k->next;
					}
					/*else if (itap(final_f, k, i, j, g) == 0 && 
							 i == (g - 1) && j == (g - 1))
					{
						k = sort_lists(lists, k->letter);
						
						i = -1;
						j = 0;
						lists = k;
						a++;
					}
					if (a > 5)
					{
						break;
						}*/
					//write(1, "D", 1);
					i++;
					//write(1, "F", 1);
				}
				i = 0;
				j++;
				//write(1, "G", 1);
			}
			//s++;
			k = k->next;// решает если подряд не помещаются
			i = 0;
			j = 0;
			//write(1, "H", 1);
		}
	//write(1, "L", 1);
	return(0);
}
/*
**
*/
char **field_in_final_f(char **final_f, t_fill *lists, int h_f, int g)
{
	t_fill *k;
	int    f;
	//printf("%d", 2);
	//f = h_f;
	f = 1;
	k = lists;
	while (f > 0)
	{
		where_coord(final_f, lists, g);
		f--;
	}
	return(final_f);
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
	k = ft_sqrt_mod(a * 4);
	//printf("%d", k);
	j = 0;
	i = 0;
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
			final_f[j][i] = '\0';
		j++;
		i = 0;
	}
	return (final_f);
}
