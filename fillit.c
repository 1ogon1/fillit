/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:15:55 by rkonoval          #+#    #+#             */
/*   Updated: 2017/02/21 16:44:45 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static	void	go_to(t_list *begin_list, char *buff)
{
	char	**map;
	int		size;
	int		n;
	t_list *begin;

	begin_list = create_list(buff, begin_list);
//	begin = begin_list;
/*	while (begin_list)
	{
		int i = 0;
		while (i < 4)
		{
			printf("[%d][%d]\n", begin_list->x[i], begin_list->y[i]);
			i++;
		}
		printf("\n");
		begin_list = begin_list->next;
	}
*/
	size = ft_strlen(buff) / 21;
	n = 0;
	while ((4 * size) > (n * n))
		n++;
	map = create_map(n);
	while (!(map = ft_alg(begin, map)))
		map = (create_map(++n));
	print_map(map);
}

static	void	fillit(int fd)
{
	int		ret;
	char	buff[546];
	t_list	*begin_list;

	begin_list = NULL;
	ret = read(fd, buff, 545);
	buff[ret] = '\0';
	if (cheacker(buff, 0, 0) == 1)
		go_to(begin_list, buff);
	else
		ft_error();
}

int				main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			ft_error();
		fillit(fd);
		close(fd);
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
