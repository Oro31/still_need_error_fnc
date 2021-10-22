/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:05:31 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/22 17:42:07 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_hadd_tolist(t_elem *list, int value)
{
	t_elem	*newelem;

	newelem = malloc(sizeof(t_elem));
	newelem->val = value;
	newelem->nxt = list;
	return (newelem);
}

t_elem	*ft_eadd_tolist(t_elem *list, int value)
{
	t_elem	*newelem;
	t_elem	*tmp;

	newelem = malloc(sizeof(t_elem));
	newelem->val = value;
	newelem->nxt = NULL;
	if (list == NULL)
		return (newelem);
	else
	{
		tmp = list;
		while (tmp->nxt != NULL)
			tmp = tmp->nxt;
		tmp->nxt = newelem;
		return (list);
	}
}

t_elem	*ft_hdelete_inlist(t_elem *list)
{
	t_elem	*ret;

	ret = list->nxt;
	if (list != NULL)
	{
		free(list);
		return (ret);
	}
	else
		return (NULL);
}

t_elem	*ft_edelete_inlist(t_elem *list)
{
	t_elem	*tmp;
	t_elem	*ptmp;

	if (list == NULL)
		return (NULL);
	if (list->nxt == NULL)
	{
		free(list);
		return (NULL);
	}
	tmp = list;
	ptmp = list;
	while (tmp->nxt)
	{
		ptmp = tmp;
		tmp = tmp->nxt;
	}
	ptmp->nxt = NULL;
	free(tmp);
	return (list);
}

void	ft_free_list(t_elem *list)
{
	t_elem	*tmp;

	if (list)
	{
		while (list)
		{
			tmp = list->nxt;
			free(list);
			list = tmp;
		}
	}
}
