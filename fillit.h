/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 12:36:20 by rkonoval          #+#    #+#             */
/*   Updated: 2017/01/26 12:10:03 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_list
{
	struct s_list	*next;
	int				x[4];
	int				y[4];
	char			c;
}					t_list;

void				push_back(t_list **begin_list, int *x, int *y, char a);
void				ft_putstr(const char *s);
void				print_map(char **map);
void				ft_putchar(char c);
void				ft_error(void);
char				**ft_alg(t_list *list, char **m);
char				**create_map(int n);
t_list				*create_list(char *s, t_list *begin_list);
t_list				*get_index(int *x, int *y, char a);
int					cheacker(char *s, int q, int p);
size_t				ft_strlen(char *s);

#endif
