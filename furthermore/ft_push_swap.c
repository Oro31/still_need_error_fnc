/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:47:16 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/22 17:02:49 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_b(t_elem **a, t_elem **b, t_estr **res, int CHUNK)
{
	int		*tab;
	int		size;
	int		set;

	tab = ft_list_to_tab(*b);
	size = ft_size_list(*b);
	tab = ft_sort(tab, size);
	set = ft_smart_rotate_b(*b, tab, size);
	if (set == 1)
	{
		while ((*b)->val != tab[size - 1])
			*b = ft_rotate(*b, 'b', res);
	}
	else if (set == 2)
	{
		while ((*b)->val != tab[size - 1])
			*b = ft_reverse_rotate(*b, 'b', res);
	}
	*a = ft_push_x_to_y(b, *a, 'a', res);
	free(tab);
}

void	ft_ra_or_rra(t_elem **a, t_elem **b, t_estr **res, int set)
{
	if (set == 1)
		*a = ft_rotate(*a, 'a', res);
	else if (set == 2)
		*a = ft_reverse_rotate(*a, 'a', res);
}

void	ft_push_swap(t_elem **a, t_elem **b, t_estr **res, int CHUNK)
{
	int		*chunkt;
	int		i;
	int		set;

	chunkt = ft_get_chunkt(*a, CHUNK);
	i = CHUNK;
	while (--i >= 0)
	{
		while (ft_is_chunk(*a, chunkt, i, CHUNK))
		{
			set = ft_smart_rotate_a(*a, chunkt, i, CHUNK);
			if (set == 0)
				*b = ft_push_x_to_y(a, *b, 'b', res);
			ft_ra_or_rra(a, b, res, set);
		}
		if (i < CHUNK - 1)
		{
			set = ft_smart_set_a(*a, chunkt, i);
			while ((*a)->val != chunkt[i + 1])
				ft_ra_or_rra(a, b, res, set);
		}
		while (*b)
			ft_set_b(a, b, res, CHUNK);
	}
	free(chunkt);
}
