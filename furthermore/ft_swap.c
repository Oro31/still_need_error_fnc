/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:57:58 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/21 13:14:55 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_swap(t_elem *list, char c, t_estr **res)
{
	int		fval;
	int		sval;

	if (list == NULL)
		return (NULL);
	else if (list->nxt == NULL)
		return (list);
	fval = list->val;
	sval = list->nxt->val;
	list = ft_hdelete_inlist(list);
	list = ft_hdelete_inlist(list);
	list = ft_hadd_tolist(list, fval);
	list = ft_hadd_tolist(list, sval);
	if (c == 'a')
		*res = ft_eadd_tolistr(*res, "sa");
	else if (c == 'b')
		*res = ft_eadd_tolistr(*res, "sa");
	return (list);
}
