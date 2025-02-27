/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:08:54 by jcremin           #+#    #+#             */
/*   Updated: 2019/04/11 10:57:19 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
**сдвигаем фигуру влево
*/
char	**turn_left(char **glade)
{
	char buf;
	int j;

	j = 0;
	while (glade[0][0] == '.' && glade[1][0] == '.' 
		   && glade[2][0] == '.' && glade[3][0] == '.')
	{
		while (j < 4)
		{
			buf = glade[j][0];
			glade[j][0] = glade[j][1];
			glade[j][1] = glade[j][2];
			glade[j][2] = glade[j][3];
			glade[j][3] = buf;
			j++;
		}
		j = 0;
	}
	return (glade);
}
/*
**сдвигаем фигуру вверх
*/
char	**turn_up(char **glade)
{
	char *buf;
 
	while (glade[0][0] == '.' && glade[0][1] == '.'
		   && glade[0][2] == '.' && glade[0][3] == '.')
	{
		buf = glade[0];
		glade[0] = glade[1];
		glade[1] = glade[2];
		glade[2] = glade[3];
		glade[3] = buf;
	}
	return (glade);
}
/*
**записываем строку в массив
*/
char	**filling_array(char *buf, char **glade, char letter)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (buf[k] != '\0')
	{
		if (buf[k] != '\n')
		{
            if (buf[k] == '#')
				glade[j][i] = letter;
            else
				glade[j][i] = buf[k];
			i++;
		}
		if (buf[k] == '\n' && j < 4)
		{
			glade[j][i] = '\0';//if (j < 3)
			i = 0;
			j++;
		}
		k++;
	}
	return (turn_left(turn_up(glade)));
	//return (turn_up(glade));
}
/*
**выделяем память под массив
*/
char	**str_to_array(char *buf, char letter)
{
	char    **glade;
	int     i;

	i = 0;
	glade = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		glade[i] = (char *)malloc(sizeof(char ) * 5);
		i++;
	}
	filling_array(buf, glade, letter);
	return (glade);
}
