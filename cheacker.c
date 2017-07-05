/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheacker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:16:06 by rkonoval          #+#    #+#             */
/*   Updated: 2017/01/24 15:04:58 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_sym(char *s)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == '.' || s[i] == '#' || s[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

static int		check_figure(char *s, int i, int k, int j)
{
	while (s[i])
	{
		if ((s[i] == '#' && s[i + 1] == '#' && s[i + 5] == '#') ||
				(s[i] == '#' && s[i + 1] == '#' && s[i - 5] == '#') ||
				(s[i] == '#' && s[i - 1] == '#' && s[i + 5] == '#') ||
				(s[i] == '#' && s[i - 1] == '#' && s[i - 5] == '#') ||
				(s[i] == '#' && s[i - 1] == '#' && s[i + 1] == '#') ||
				(s[i] == '#' && s[i - 5] == '#' && s[i + 5] == '#'))
			j++;
		if (s[i] == '#' && (s[i + 1] == '#' || s[i + 5] == '#' ||
					s[i - 1] == '#' || s[i - 5] == '#'))
			k += 1;
		if (s[i] == '\n' && s[i + 1] == '\n' && k == 4 && j != 0)
		{
			k = 0;
			j = 0;
		}
		i++;
	}
	if (k == 4 && j != 0)
		return (1);
	return (0);
}

int				cheacker(char *s, int q, int p)
{
	int i;

	i = 0;
	if ((ft_strlen(s) + 1) % 21 == 0 && check_sym(s) == 1 &&
			check_figure(s, 0, 0, 0) == 1)
	{
		while (s[i])
		{
			if (s[i] == '#')
				q += 1;
			if (s[i] == '.')
				p += 1;
			if (s[i] == '\n' && s[i + 1] == '\n' && q == 4 && p == 12)
			{
				q = 0;
				p = 0;
			}
			i++;
		}
	}
	if (q == 4 && p == 12)
		return (1);
	return (0);
}
