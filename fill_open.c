/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:33:21 by jcremin           #+#    #+#             */
/*   Updated: 2019/04/13 18:32:27 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//#include "fill_format.c"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

/*
**из строки в массив, цельная функция с выделением памяти(далее разделена на 2) 
*/
/*
char	**str_to_array(char *buf, char letter)
{
	char	**pole;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	pole = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		pole[i] = (char *)malloc(sizeof(char ) * 5);
		i++;
	}
	i = 0;
	while (buf[k] != '\0')
	{
		if (buf[k] != '\n')
		{
			if (buf[k] == '#')
				pole[j][i] = letter;
			else
				pole[j][i] = buf[k];
			i++;
		}
		if (buf[k] == '\n' && j < 4)
		{
			pole[j][i] = '\0';
			i = 0;
			if (j < 3)
				j++;
		}
		k++;
	}
	return (pole);
}
*/
/*
**запись блоков в листы
*/

int		add_field(int fd, t_fill *list)
{
	int		br;
	t_fill	*p;
	char	bank[22];
	char	*trash;
	int j = 0;

	p = list;
	while (p != NULL)
	{
		br = read(fd, bank, 21);
		bank[br - 1] = '\0';
		p->field = str_to_array(bank, p->letter);
		p = p->next;
	}
	j = 0;
	p = list;
/*
	while (p != NULL)
    {
        printf("list %c:\n", p->letter);
        while (j < 4)
        {
            printf("%s\n", p->field[j]);
            j++;
        }
        printf("%c", '\n');
        j = 0;
        p = p->next;
    }
*/
	return (0);
}

/* 
**создаем кол-во листов равное кол-ву блоков
*/

t_fill		*push(int count)
{
	t_fill	*lst;
	t_fill	*temp;
	t_fill	*p;
	int		i;

	i = 65;
	lst = (t_fill*)malloc(sizeof(t_fill));
	lst->next = NULL;
	lst->letter = i;
	lst->last = NULL;
	while (count - 1 > 0)
	{
		p = lst;
		while (p->next != NULL)
		{
			p = p->next;
		}
		temp = (t_fill*)malloc(sizeof(t_fill));
		temp->next = NULL;
		temp->letter = i + 1;
		temp->last = p;
		p->next = temp;
		count--;
		i++;
	}
	p = lst;
	return (lst);
}

/*
**считаем сколько блоков с тетриминами у нас
*/

int	how_fields(int fd)
{
	int		br;
	int		i;
	int		j;
	char	buf[568];

	i = 0;
	j = 0;
	br = read(fd, buf, 568);
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			j++;
		}
		i++;
	}
	return (j / 5);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_fill	*k;
	t_fill  *k1;
	char	**f_f;
	int		i;
	int		j;
	int a;
	int b;
	int		h_f;

	a = 0;
	b = 0;
	i = 1;
	j = 0;
	fd = open(argv[1], O_RDONLY);
	h_f = how_fields(fd);
	//printf("%d", h_f);
	k = push(h_f);

	//printf("%c", '\n');
	close(fd);
	fd = open(argv[1], O_RDONLY);
	add_field(fd, k);

	/*k1 = k;
	while (k1 != NULL)
    {
        //write(1, &k->field, 1);
        printf("%c", k1->letter);
        k1 = k1->next;
    }
	*/
	f_f = create_final_f(h_f);

	f_f = field_in_final_f(f_f, k, h_f, ft_sqrt_mod(h_f * 4));
	write(1, "OOO\n\n", 5);
	while (j < 5)
	{
		printf("%s\n", f_f[j]);
		j++;
		if (i > 20)
		{
			break;
		}
		i++;
		}

/*	while (k->next != NULL)
	{
		write(1, "1", 1);
		k = k->next;
	}
	while (k->last != NULL)
	{
		write(1, "2", 1);
		while (j < 4)
		{
			write(1, "3", 1);
            printf("%s\n", k->field[0]);
			write(1, "4", 1);
            j++;
			write(1, "5", 1);
		}
		write(1, "6", 1);
		j = 0;
		k->last->next = k;
		k = k->last;
	}*/

	//field_in_final_f(f_f, k, h_f);

	//printf("%s", k->field[0]);

	//printf("%d", h_f);
	
	//k = sort_lists(k, 'C');
/*	k1 = k;
	while (k1 != NULL)
	{
		printf("list %c:\n", k1->letter);
		while (j < 4)
		{
			printf("%s\n", k1->field[j]);
			j++;
		}
		printf("%c", '\n');
		j = 0;
		k1 = k1->next;
	}
*/
	close(fd);
	return (0);
}
