/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:58:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/21 14:25:36 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_rotate(t_elem *list, char c, t_estr **res)
{
	int		val;

	if (list == NULL)
		return (NULL);
	else if (list->nxt == NULL)
		return (list);
	val = list->val;
	list = ft_hdelete_inlist(list);
	list = ft_eadd_tolist(list, val);
	if (c == 'a')
		*res = ft_eadd_tolistr(*res, "ra");
	else if (c == 'b')
		*res = ft_eadd_tolistr(*res, "rb");
	return (list);
}
