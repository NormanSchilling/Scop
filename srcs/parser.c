/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 13:51:54 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/01 15:43:14 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_listvertex		*get_listvertex(int fd)
{
	int				i;
	char			*line;
	char			**vertex;
	t_listvertex	*listvertex;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'v')
		{
			vertex = ft_strsplit(line, ' ');
			i = 1;
			while (vertex[i] != NULL)
			{
				listvertex_pushback(&listvertex, ft_listvertex_new(ft_atof(vertex[i])));
				i++;
			}
			free(line);
		}
	}
	return (listvertex);
}

float		*get_buffvertex(t_opengl *o)
{
	int				i;
	float			*buffvertex;
	t_listvertex	*tmp;

	tmp = o->listvertex;

	i = listvertex_size(o->listvertex);
	printf("%d\n", i);
	buffvertex = (float*)malloc(sizeof(float) * i);
	if (buffvertex == NULL)
		exit(-1);
	i = 0;
	while (tmp->next != NULL)
	{
		buffvertex[i] = o->listvertex->point;
		tmp = tmp->next;
		i++;
	}
	return (buffvertex);
}

void		parser(t_opengl *o)
{
	int				fd;

	fd = open("resources/42.obj", O_RDONLY);
	o->listvertex = get_listvertex(fd);
	o->buffvertex = get_buffvertex(o);
	close(fd);
}