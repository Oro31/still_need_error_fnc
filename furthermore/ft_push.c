/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:32:35 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/21 13:11:46 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_push_x_to_y(t_elem **x, t_elem *y, char c, t_estr **res)
{
	int		xval;

	if (*x == NULL)
		return (y);
	xval = (*x)->val;
	y = ft_hadd_tolist(y, xval);
	*x = ft_hdelete_inlist(*x);
	if (c == 'a')
		*res = ft_eadd_tolistr(*res, "pa");
	else if (c == 'b')
		*res = ft_eadd_tolistr(*res, "pb");
	return (y);
}
