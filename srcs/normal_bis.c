/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 10:48:56 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/08 11:20:01 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			*get_indices(t_opengl *o, int j)
{
	int		*indices;

	indices = (int*)malloc(sizeof(int) * 3);
	if (indices != NULL)
	{
		indices[0] = o->bufffragment[j];
		indices[1] = o->bufffragment[j + 1];
		indices[2] = o->bufffragment[j + 2];
	}
	else
		exit(-1);
	return (indices);
}

t_vertex	*get_vertex_of_indices(t_opengl *o, int *indices)
{
	t_vertex		*vertex;

	vertex = (t_vertex*)malloc(sizeof(t_vertex) * 3);
	if (vertex != NULL)
	{
		vertex[0].x = o->buffvertex[indices[0] * 3];
		vertex[0].y = o->buffvertex[indices[0] * 3 + 1];
		vertex[0].z = o->buffvertex[indices[0] * 3 + 2];
		vertex[1].x = o->buffvertex[indices[1] * 3];
		vertex[1].y = o->buffvertex[indices[1] * 3 + 1];
		vertex[1].z = o->buffvertex[indices[1] * 3 + 2];
		vertex[2].x = o->buffvertex[indices[2] * 3];
		vertex[2].y = o->buffvertex[indices[2] * 3 + 1];
		vertex[2].z = o->buffvertex[indices[2] * 3 + 2];
	}
	else
		exit(-1);
	return (vertex);
}

void		set_buffnormal(t_opengl *o, int *indices, t_vertex vector)
{
	o->buffnormal[indices[0]] = add_vertex(
		o->buffnormal[indices[0]], vector);
	o->buffnormal[indices[1]] = add_vertex(
		o->buffnormal[indices[1]], vector);
	o->buffnormal[indices[2]] = add_vertex(
		o->buffnormal[indices[2]], vector);
}

void		set_normalize(t_opengl *o, unsigned long i)
{
	unsigned long	j;

	j = 0;
	while (j < sizeof(t_vertex) * (i / 3))
	{
		o->buffnormal[j] = normalize(o->buffnormal[j]);
		j++;
	}
}
