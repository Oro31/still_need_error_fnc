/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:46:48 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/22 16:58:27 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_list_sort(t_elem *list)
{
	t_elem	*tmp;

	if (list == NULL)
		return (-1);
	tmp = list;
	while (tmp->nxt)
	{
		if (tmp->val > tmp->nxt->val)
			return (0);
		tmp = tmp->nxt;
	}
	return (1);
}

int	ft_is_tab_sort(int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
	}
	return (1);
}

int	*ft_list_to_tab(t_elem *list)
{
	t_elem	*tmp;
	int		*tab;
	int		size;
	int		i;

	if (list == NULL)
		return (NULL);
	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->nxt;
		i++;
	}
	size = i;
	tab = malloc(sizeof(int) * size);
	tmp = list;
	i = -1;
	while (++i < size)
	{
		tab[i] = tmp->val;
		tmp = tmp->nxt;
	}
	return (tab);
}

int	*ft_sort(int *tab, int size)
{
	int	*res;
	int	tmp;
	int	i;

	res = malloc(sizeof(int) * size);
	if (!res)
		return (0);
	i = -1;
	while (++i < size)
		res[i] = tab[i];
	while (!ft_is_tab_sort(res, size))
	{
		i = -1;
		while (++i < size - 1)
		{
			if (res[i] > res[i + 1])
			{
				tmp = res[i];
				res[i] = res[i + 1];
				res[i + 1] = tmp;
			}
		}
	}
	free(tab);
	return (res);
}
