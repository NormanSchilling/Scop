/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 13:51:54 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/01 17:55:43 by nschilli         ###   ########.fr       */
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

t_listfragment		*get_listfragment(int fd)
{
	int				i;
	char			*line;
	char			**frag;
	t_listfragment	*listfragment;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'f')
		{
			frag = ft_strsplit(line, ' ');
			i = 1;
			while (frag[i] != NULL)
			{
				listfragment_pushback(&listfragment, ft_listfragment_new(ft_atoi(frag[i])));
				i++;
			}
			free(line);
		}
	}
	return (listfragment);
}

float		*get_buffvertex(t_opengl *o)
{
	int				i;
	GLfloat			*buffvertex;
	t_listvertex	*tmp;

	tmp = o->listvertex;

	i = listvertex_size(o->listvertex);
	buffvertex = (GLfloat*)malloc(sizeof(GLfloat) * i);
	if (buffvertex == NULL)
		exit(-1);
	i = 0;
	while (tmp->next != NULL)
	{
		printf("o->listvertex->point = %f\n", o->listvertex->point);
		buffvertex[i] = o->listvertex->point;
		printf("buffvertex[i] = %f\n", buffvertex[i]);
		tmp = tmp->next;
		i++;
	}
	return (buffvertex);
}

int		*get_bufffragment(t_opengl *o)
{
	int				i;
	GLint			*bufffragment;
	t_listfragment	*tmp;

	tmp = o->listfragment;

	i = listfragment_size(o->listfragment);
	bufffragment = (GLint*)malloc(sizeof(GLint) * i);
	if (bufffragment == NULL)
		exit(-1);
	i = 0;
	while (tmp->next != NULL)
	{
		bufffragment[i] = o->listfragment->point;
		tmp = tmp->next;
		i++;
	}
	return (bufffragment);
}

void		parser(t_opengl *o)
{
	int				fd;

	fd = open("resources/42.obj", O_RDONLY);
	o->listvertex = get_listvertex(fd);
	o->buffvertex = get_buffvertex(o);
	fd = open("resources/42.obj", O_RDONLY);
	o->listfragment = get_listfragment(fd);
	o->bufffragment = get_bufffragment(o);
	close(fd);
}