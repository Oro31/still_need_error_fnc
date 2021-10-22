/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:57:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/22 17:56:06 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_list(t_elem *list)
{
	t_elem	*tmp;
	int		i;

	if (list == NULL)
		return (0);
	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->nxt;
		i++;
	}
	return (i);
}

int	ft_size_listr(t_estr *list)
{
	t_estr	*tmp;
	int		i;

	if (list == NULL)
		return (0);
	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->nxt;
		i++;
	}
	return (i);
}

void	ft_print_list(t_estr *res)
{
	t_estr	*tmp;

	if (res == NULL)
		ft_print_str("(null)");
	else
	{
		tmp = res;
		while (tmp)
		{
			ft_print_str(tmp->str);
			ft_print_str("\n");
			tmp = tmp->nxt;
		}
	}
}

t_elem	*ft_copy_list(t_elem *list)
{
	t_elem	*tmp;
	t_elem	*copy;

	if (list == NULL)
		return (NULL);
	copy = NULL;
	tmp = list;
	while (tmp)
	{
		copy = ft_eadd_tolist(copy, tmp->val);
		tmp = tmp->nxt;
	}
	return (copy);
}

t_estr	*ft_copy_listr(t_estr *listr)
{
	t_estr	*tmp;
	t_estr	*copy;

	if (listr == NULL)
		return (NULL);
	copy = NULL;
	tmp = listr;
	while (tmp)
	{
		copy = ft_eadd_tolistr(copy, tmp->str);
		tmp = tmp->nxt;
	}
	return (copy);
}
