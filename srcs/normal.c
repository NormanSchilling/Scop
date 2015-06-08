/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 13:06:29 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/08 11:21:53 by nschilli         ###   ########.fr       */
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
	int				*indices;
	t_vertex		*vertex;
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
		indices = get_indices(o, j);
		vertex = get_vertex_of_indices(o, indices);
		vector[0] = soustract_vertex(vertex[0], vertex[1]);
		vector[1] = soustract_vertex(vertex[0], vertex[2]);
		vector[0] = normalize(cross_vertex(vector[0], vector[1]));
		set_buffnormal(o, indices, vector[0]);
		j += 3;
	}
	free(indices);
	free(vector);
	free(vertex);
	set_normalize(o, i);
}
