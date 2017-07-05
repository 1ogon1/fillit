/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:11:39 by rkonoval          #+#    #+#             */
/*   Updated: 2017/01/24 15:27:44 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list			*get_index(int *x, int *y, char a)
{
	t_list	*elem;
	int		i;

	i = 0;
	elem = malloc(sizeof(t_list));
	while (i < 4)
	{
		elem->x[i] = x[i];
		elem->y[i] = y[i];
		i++;
	}
	elem->c = a;
	return (elem);
}

static t_list	*get_block(char *s, int i, t_list *begin, char a)
{
	int		j;
	int		k;
	int		x[4];
	int		y[4];

	j = 0;
	k = 0;
	while (j < i)
	{
		if (s[j] == '#')
		{
			x[k] = j % 5;
			y[k] = j / 5;
			k++;
		}
		j++;
	}
	push_back(&begin, x, y, a);
	return (begin);
}

t_list			*create_list(char *s, t_list *begin_list)
{
	int		i;
	char	a;
	t_list	*begin;

	begin = NULL;
	a = 'A';
	i = 0;
	begin_list = get_block(&s[i], 20, begin, a);
	i = 21;
	a = 'B';
	begin = begin_list;
	while (s[i])
	{
		get_block(&s[i], 20, begin_list, a);
		a += 1;
		i += 21;
	}
	return (begin);
}
