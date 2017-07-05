/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:48:35 by rkonoval          #+#    #+#             */
/*   Updated: 2017/02/13 11:05:26 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_erase(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

static int		ft_fit(t_list *begin_list, char **map, int y, int x)
{
	int		i;
	int		j;
	int		k;
	int		size;

	size = ft_strlen(map[0]);
	j = y;
	i = x;
	k = 0;
	while (i >= 0 && i < size &&
			j >= 0 && j < size &&
			map[i][j] == '.' && k < 4)
	{
		map[i][j] = begin_list->c;
		k++;
		j += (begin_list->x[k] - begin_list->x[k - 1]);
		i += (begin_list->y[k] - begin_list->y[k - 1]);
	}
	return (k);
}

char			**ft_alg(t_list *list, char **m)
{
	int		i[3];

	i[0] = -1;
	i[2] = 0;
	while (m[++i[0]])
	{
		i[1] = -1;
		while (m[i[0]][++i[1]])
		{
			if (m[i[0]][i[1]] == '.' && (i[2] = ft_fit(list, m, i[1], i[0])))
			{
				if (i[2] != 4 && !(i[2] = 0))
					ft_erase(m, list->c);
				else if (i[2] == 4 && list->next != NULL)
				{
					if (ft_alg(list->next, m))
						return (m);
					ft_erase(m, list->c);
				}
				else
					return (m);
			}
		}
	}
	return (0);
}
