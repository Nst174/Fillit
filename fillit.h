/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:30:27 by jcremin           #+#    #+#             */
/*   Updated: 2019/04/08 16:45:44 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FILLIT_H
# define FILLIT_H
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

char    **str_to_array(char *buf, char letter);
char	**create_final_f(int a);


typedef struct				f_fill
{
	char			**field;
	//int			number;
	char			letter;
	struct f_fill	*next;
	struct f_fill	*last;
}							t_fill;

t_fill	*sort_lists(t_fill *ed_lists, char let);
char	**field_in_final_f(char **final_f, t_fill *lists, int h_f, int g);
void	print(t_fill *lists);


#endif
