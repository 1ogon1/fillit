/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:56:07 by rkonoval          #+#    #+#             */
/*   Updated: 2017/01/24 15:19:02 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	push_back(t_list **begin_list, int *x, int *y, char a)
{
	t_list *end;
	t_list *header;

	end = get_index(x, y, a);
	if (*begin_list != NULL)
	{
		header = *begin_list;
		while (header->next != NULL)
			header = header->next;
		header->next = end;
	}
	else
		(*begin_list) = end;
	end->next = NULL;
}
