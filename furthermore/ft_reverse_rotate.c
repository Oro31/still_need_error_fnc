/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:20:18 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/21 13:12:47 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_reverse_rotate(t_elem *list, char c, t_estr **res)
{
	t_elem	*tmp;
	int		val;

	if (list == NULL)
		return (NULL);
	else if (list->nxt == NULL)
		return (list);
	tmp = list;
	while (tmp->nxt)
		tmp = tmp->nxt;
	val = tmp->val;
	list = ft_edelete_inlist(list);
	list = ft_hadd_tolist(list, val);
	if (c == 'a')
		*res = ft_eadd_tolistr(*res, "rra");
	else if (c == 'b')
		*res = ft_eadd_tolistr(*res, "rrb");
	return (list);
}
