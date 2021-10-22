/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_rotate_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:39:37 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/22 16:16:11 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_smart_rotate_b(t_elem *b, int *sort, int size)
{
	int		*tab;
	int		tsize;
	int		j;
	int		k;

	tab = ft_list_to_tab(b);
	tsize = ft_size_list(b);
	j = 0;
	while (tab[j] != sort[size - 1])
		j++;
	k = tsize - 1;
	while (tab[k] != sort[size - 1])
		k--;
	k = tsize - k;
	free(tab);
	if (j == 0 || k == 0)
		return (0);
	else if (j < k)
		return (1);
	else
		return (2);
}
