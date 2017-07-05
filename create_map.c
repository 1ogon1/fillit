/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:22:53 by rkonoval          #+#    #+#             */
/*   Updated: 2017/01/23 16:18:59 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*push_dots(int n, char *map)
{
	int i;

	i = 0;
	while (i < n)
	{
		map[i] = '.';
		i++;
	}
	map[i] = '\0';
	return (map);
}

char		**create_map(int n)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (n + 1));
	while (i < n)
	{
		map[i] = (char *)malloc(sizeof(char) * (n + 1));
		map[i] = push_dots(n, map[i]);
		i++;
	}
	map[i] = 0;
	return (map);
}
