/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fragment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 17:07:01 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/02 12:07:28 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		listfragment_size(t_listfragment *beginlist)
{
	t_listfragment	*node;
	int				i;

	i = 0;
	node = beginlist;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void	listfragment_pushback(t_listfragment **beginlist, t_listfragment *newlist)
{
	t_listfragment	*tmp;

	tmp = *beginlist;
	if (tmp == NULL)
		*beginlist = newlist;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newlist;
	}
}

t_listfragment	*ft_listfragment_new(float point)
{
	t_listfragment	*node;

	node = NULL;
	node = (t_listfragment *)malloc(sizeof(t_listfragment));
	if (node == NULL)
		return (NULL);
	else
	{
		node->point = point;
		node->next = NULL;
	}
	return (node);
}
