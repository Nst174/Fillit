/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:48:26 by jcremin           #+#    #+#             */
/*   Updated: 2019/04/11 11:20:53 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fff(char **final_f, int g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < g)
	{
		while (i < g)
		{
			if (final_f[j][i] != '.')
				final_f[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
}

int    print3(char **f_f)
{
    int j;
    int i;

    i = 0;
    j = 0;
    while (f_f[j][i] != '\0')
    {
        while (j < 4)
        {
            while (i < 4)
            {
                write(1, &f_f[j][i], 1);
                i++;
            }
            write(1, "\n", 1);
            j++;
            i = 0;
        }
        write(1, "\n", 1);
        j = 0;
    }
	return(0);
}

void	print2(t_fill *lists)
{
	int j;
	int i;

	i = 0;
    j = 0;
    while (lists != NULL)
    {
        while (j < 4)
        {
			while (i < 4)
			{
				write(1, &lists->field[j][i], 1);
				i++;
			}
            write(1, "\n", 1);
            j++;
			i = 0;
        }
        write(1, "\n", 1);
        j = 0;
        lists = lists->next;
    }
}
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

void sort_b_m(t_fill *sort_mass)
{
	t_fill *sm;
	t_fill *l1;
    t_fill *l2;
    t_fill *n1;
    t_fill *n2;
    t_fill *u1;
    t_fill *u2;

	write(1, "S-20\n", 5);
	sm = sort_mass;
	while (sm->next != NULL)
	{
		u1 = sm;
		l1 = sm->last;
		n1 = sm->next;
		u2 = sm->next;
		l2 = sm->next->last;
		n2 = sm->next->next;
		write(1, "S-21\n", 5);
		if (sm->letter > sm->next->letter)
		{
			write(1, "S-22\n", 5);
			l1->next = u2;
			n2->last = u1;
			u1->next = n2;
			u1->last = n1;
			u2->next = l2;
			u2->last = l1;
			sm = u2;
		}
		else
		{
			write(1, "S-23\n", 5);
			sm = sm->next;
		}
		write(1, "S-24\n", 5);
	}
	write(1, "S-25\n", 5);
}

t_fill *sort_lists(t_fill *ed_lists, char let, int g)
{
	int i;
	int j;
	int pp;
	t_fill *p;
	t_fill *r;
	t_fill *s;
	t_fill *t;
	t_fill *l1;
	t_fill *l2;
	t_fill *n1;
	t_fill *n2;
	t_fill *u1;
	t_fill *u2;
	char letter1;
	char **field1;

	pp = 0;
	write(1, "S-1\n", 4);
	i = 0;
	p = ed_lists;
	while (p->letter != let)
	{
		write(1, "S-2\n", 4);
		p = p->next;
		i++;
	}
	write(1, "S-3\n", 4);
	p = ed_lists;
	while ((i - 1) > 0)
	{
		write(1, "S-4\n", 4);
		p = p->next;
		i--;
	}
	if ((p->letter - 65) == (g - 1))
	{
		write(1, "S-5\n", 4);
		p = p->last;
		}
	write(1, "S-6\n", 4);
	u1 = p;
	l1 = p->last;
	n1 = p->next;
	r = u1;
	j = 1;
	write(1, "S-7\n", 4);
	while (r->letter != u1->letter + j)
	{
		write(1, "S-8\n", 4);
		if (r  ==  NULL)
		{
			write(1, "S-9\n", 4);
			j++;
			r = u1;
		}
		r = r->next;
	}
	write(1, "S-10\n", 5);
	u2 = r;
	write(1, "S-11\n", 5);
	l2 = r->last;
	write(1, "S-12\n", 5);
	n2 = r->next;
	write(1, "S-13\n", 5);
//	write(1, &r->letter, 1);

	if (n2 == NULL)
	{
		write(1, "S-13-1\n", 7);
		u1->next = n2;
        u1->last = n1;
        u2->next = l2;
        u2->last = l1;
		n1->next = u1;
		n1->last = u2;
		l1->next = u2;
	}
	else if (u1->last == NULL)
	{
		write(1, "S-999\n", 6);
		letter1 = u1->letter;
		field1 = u1->field;
		u1->letter = u2->letter;
		u1->field = u2->field;
		u2->letter = letter1;
		u2->field = field1;
		/*
		u1->next = n2;
		u1->last = n1;
		u2->next = l2;
		u2->last = l1;
		n1->next = u1;
        n1->last = u2;
		n2->last = u1;
		*/
	}
	else
	{	
		l1->next = u2;
		write(1, "S-14\n", 5);
		n2->last = u1;
		write(1, "S-15\n", 5);
		u1->next = n2;
		write(1, "S-16\n", 5);
		u1->last = n1;
		write(1, "S-17\n", 5);
		u2->next = l2;
		write(1, "S-18\n", 5);
		u2->last = l1;
	}
	sort_b_m(u2->next);	
	
/*	
	n1->last = u2;
	l2->next = u1;
	u1->last = l2;
	u1->next = l1;
	u2->last = n2;
	u2->next = n1;
*/
	write(1, "S-19\n", 5);
	//write(1, "B", 1);
	//print(ed_lists);
	return (ed_lists);
}
