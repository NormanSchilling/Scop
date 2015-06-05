/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 13:06:29 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/05 13:55:08 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vertex	normalize(t_vertex v)
{
	float		size;
	t_vertex	vertex_normal;

	size = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	vertex_normal.x = v.x / size;
	vertex_normal.y = v.y / size;
	vertex_normal.z = v.z / size;
	return (vertex_normal);
}

t_vertex	cross_vertex(t_vertex v, t_vertex v2)
{
	t_vertex		new_vertex;

	new_vertex.x = v.y * v2.z - v.z * v2.y;
	new_vertex.y = v.z * v2.x - v.x * v2.z;
	new_vertex.z = v.x * v2.y - v.y * v2.x;
	return (new_vertex);
}


t_vertex	add_vertex(t_vertex v, t_vertex v2)
{
	t_vertex		new_vertex;

	new_vertex.x = v.x + v2.x;
	new_vertex.y = v.y + v2.y;
	new_vertex.z = v.z + v2.z;
	return (new_vertex);
}

t_vertex	soustract_vertex(t_vertex v, t_vertex v2)
{
	t_vertex		new_vertex;

	new_vertex.x = v.x - v2.x;
	new_vertex.y = v.y - v2.y;
	new_vertex.z = v.z - v2.z;
	return (new_vertex);
}

void		get_buffnormal(t_opengl *o)
{		
	int				indices[3];
	t_vertex		vertex[3];
	t_vertex		vector[2];
	unsigned long	i;
	unsigned long	j;

	i = listvertex_size(o->listvertex);
	o->buffnormal = (t_vertex*)malloc(sizeof(t_vertex) * (i / 3));
	ft_bzero(o->buffnormal, sizeof(t_vertex) * (i / 3));
	j = 0;
	i = listfragment_size(o->listfragment);
	while (j < i)
	{
		indices[0] = o->bufffragment[j];
		indices[1] = o->bufffragment[j + 1];
		indices[2] = o->bufffragment[j + 2];
		vertex[0].x = o->buffvertex[indices[0] * 3];
		vertex[0].y = o->buffvertex[indices[0] * 3 + 1];
		vertex[0].z = o->buffvertex[indices[0] * 3 + 2];
		vertex[1].x = o->buffvertex[indices[1] * 3];
		vertex[1].y = o->buffvertex[indices[1] * 3 + 1];
		vertex[1].z = o->buffvertex[indices[1] * 3 + 2];
		vertex[2].x = o->buffvertex[indices[2] * 3];
		vertex[2].y = o->buffvertex[indices[2] * 3 + 1];
		vertex[2].z = o->buffvertex[indices[2] * 3 + 2];
		vector[0] = soustract_vertex(vertex[0], vertex[1]);
		vector[1] = soustract_vertex(vertex[0], vertex[2]);
		vector[0] = normalize(cross_vertex(vector[0], vector[1]));
		o->buffnormal[indices[0]] = add_vertex(o->buffnormal[indices[0]], vector[0]);
		o->buffnormal[indices[1]] = add_vertex(o->buffnormal[indices[1]], vector[0]);
		o->buffnormal[indices[2]] = add_vertex(o->buffnormal[indices[2]], vector[0]);
		j += 3;
	}
	j = 0;
	while (j < sizeof(t_vertex) * (i / 3))
	{
		o->buffnormal[j] = normalize(o->buffnormal[j]);
		j++;
	}
}