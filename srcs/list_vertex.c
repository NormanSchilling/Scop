/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_vertex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 15:01:30 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/01 15:15:48 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		listvertex_size(t_listvertex *beginlist)
{
	t_listvertex	*node;
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


void	listvertex_pushback(t_listvertex **beginlist, t_listvertex *newlist)
{
	t_listvertex	*tmp;

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


t_listvertex	*ft_listvertex_new(float point)
{
	t_listvertex	*node;

	if ((node = (t_listvertex *)malloc(sizeof(t_listvertex))) == NULL)
		return (NULL);
	node->point = point;
	node->next = NULL;
	return (node);
}