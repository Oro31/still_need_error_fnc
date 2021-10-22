/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:05:31 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/22 17:48:11 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_estr	*ft_hadd_tolistr(t_estr *list, char *str)
{
	t_estr	*newelem;

	newelem = malloc(sizeof(t_estr));
	newelem->str = str;
	newelem->nxt = list;
	return (newelem);
}

t_estr	*ft_eadd_tolistr(t_estr *list, char *str)
{
	t_estr	*newelem;
	t_estr	*tmp;

	newelem = malloc(sizeof(t_estr));
	newelem->str = str;
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

void	ft_free_listr(t_estr *listr)
{
	t_estr	*tmp;

	while (listr)
	{
		tmp = listr->nxt;
		/*if (listr->str)
			free(listr->str);*/
		free(listr);
		listr = tmp;
	}
}
