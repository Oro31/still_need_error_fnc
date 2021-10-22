/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:54:08 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/22 16:15:07 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_chunk(t_elem *list, int *chunkt, int i, int CHUNK)
{
	t_elem	*tmp;
	int		m;

	if (list == NULL)
		return (0);
	tmp = list;
	m = 0;
	if (i == CHUNK - 1)
		m = 1;
	while (tmp)
	{
		if (tmp->val >= chunkt[i] && tmp->val < chunkt[i + 1] + m)
			return (1);
		tmp = tmp->nxt;
	}
	return (0);
}

int	*ft_get_chunkt(t_elem *a, int CHUNK)
{
	int		*chunkt;
	int		*sort;
	int		size;
	int		i;

	sort = ft_list_to_tab(a);
	size = ft_size_list(a);
	sort = ft_sort(sort, size);
	chunkt = malloc(sizeof(int) * (CHUNK + 1));
	if (!chunkt)
		return (NULL);
	chunkt[0] = sort[0];
	chunkt[CHUNK] = sort[size - 1];
	i = 0;
	while (++i < CHUNK)
		chunkt[i] = sort[i * (size / CHUNK)];
	free(sort);
	return (chunkt);
}
