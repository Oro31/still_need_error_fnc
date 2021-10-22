/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_or_rra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:26:08 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/22 16:15:56 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_smart_rotate_a(t_elem *a, int *chunkt, int i, int CHUNK)
{
	int		*tab;
	int		tsize;
	int		j;
	int		k;

	if (i == CHUNK - 1)
		return (ft_smart_rotate_a_max(a, chunkt, CHUNK));
	tab = ft_list_to_tab(a);
	tsize = ft_size_list(a);
	j = 0;
	while (tab[j] < chunkt[i] || tab[j] >= chunkt[i + 1])
		j++;
	k = tsize - 1;
	while (tab[k] < chunkt[i] || tab[k] >= chunkt[i + 1])
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

int	ft_smart_rotate_a_max(t_elem *a, int *chunkt, int CHUNK)
{
	int		*tab;
	int		tsize;
	int		j;
	int		k;

	tab = ft_list_to_tab(a);
	tsize = ft_size_list(a);
	j = 0;
	while (tab[j] < chunkt[CHUNK - 1])
		j++;
	k = tsize - 1;
	while (tab[k] < chunkt[CHUNK - 1])
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
