/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:48:26 by jcremin           #+#    #+#             */
/*   Updated: 2019/04/08 17:30:56 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



void	print(t_fill *lists)
{
	int j;
	j = 0;
	while (lists->next != NULL)
	{
		printf("lists %c:\n", lists->letter);
		while (j < 4)
		{
			printf("%s\n", lists->field[j]);
			j++;
		}
		printf("%c", '\n');
		j = 0;
		lists = lists->next;
	}
}

t_fill *sort_lists(t_fill *ed_lists, char let)
{
	int i;
	t_fill *p;
	t_fill *r;
	t_fill *s;
	t_fill *t;
	t_fill *last1;
	t_fill *last2;
	t_fill *next1;
	t_fill *next2;
	t_fill *uz1;
	t_fill *uz2;

	i = 0;
	p = ed_lists;
	while (p->letter != let)
	{
		p = p->next;
		i++;
	}
	uz1 = p;
	last1 = p->last;
	next1 = p->next;
	
	r = ed_lists;
	while ((i - 1) > 0)
	{
		r = r->next;
		i--;
	}
	uz2 = r;
	last2 = r->last;
	next2 = r->next;
	//блок замены листов местами
	next1->last = uz2;
	last2->next = uz1;
	uz1->last = last2;
	uz1->next = last1;
	uz2->last = next2;
	uz2->next = next1;
	
/*	write(1, "S\n", 2);
	r = ed_lists;
	i = 0;
	while (r->letter != let)
	{
		write(1, "1", 1);
		r = r->next;
		i++;
	}
	p = ed_lists;
	while ((i - 1) > 0)
	{
		write(1, "2", 1);
		p = p->next;//B
		i--;
	}
	//r = ed_lists;
	while (r->letter != p->letter + 1)
	{
		write(1, "3", 1);
		r = r->next;//C
	}
	write(1, "4", 1);
	s = p; //записали положение В
	write(1, "5", 1);
	s->next = NULL;//убрали у В следущую ссылку
	write(1, "6", 1);
	p = r; //записали указатель на С
	write(1, "7", 1);
	t = r->next;//записали указатель на следующий после С лист
	write(1, "8", 1);
	p->next = s; 
	write(1, "9", 1);
	s->next = t;
	write(1, "F\n", 2);*/
	//ed_lists->next = p;
	return (ed_lists);
}
