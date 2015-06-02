/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 13:51:54 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/02 14:57:30 by nschilli         ###   ########.fr       */
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
	listvertex = NULL;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'v')
		{
			vertex = ft_strsplit(line, ' ');
			i = 1;
			while (i < get_size_of_split(vertex))
			{
				listvertex_pushback(&listvertex, ft_listvertex_new(ft_atof(vertex[i])));
				i++;
			}
			i = 0;
			while (i++ < get_size_of_split(vertex))
				free(vertex[i - 1]);
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
	listfragment = NULL;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'f')
		{
			frag = ft_strsplit(line, ' ');
			i = get_size_of_split(frag);
			if (i == 4)
				get_first_triangle(&listfragment, frag, i);
			else if (i == 5)
			{
				get_first_triangle(&listfragment, frag, i - 1);
				get_second_triangle(&listfragment, frag, i);
			}
			i = 0;
			while (i++ < get_size_of_split(frag))
				free(frag[i - 1]);
			free(line);
		}
	}
	return (listfragment);
}

void		get_buffvertex(t_opengl *o)
{
	int				i;
	t_listvertex	*tmp;

	tmp = o->listvertex;

	i = listvertex_size(o->listvertex);
	o->buffvertex = (float*)malloc(sizeof(float) * i);
	if (o->buffvertex == NULL)
		exit(-1);
	i = 0;
	while (tmp != NULL)
	{
		o->buffvertex[i] = tmp->point;
		tmp = tmp->next;
		i++;
	}
}

void		get_bufffragment(t_opengl *o)
{
	int				i;
	t_listfragment	*tmp;

	tmp = o->listfragment;

	i = listfragment_size(o->listfragment);
	o->bufffragment = (int*)malloc(sizeof(int) * i);
	if (o->bufffragment == NULL)
		exit(-1);
	i = 0;
	while (tmp != NULL)
	{
		o->bufffragment[i] = tmp->point;
		tmp = tmp->next;
		i++;
	}
}

void		parser(t_opengl *o)
{
	int				fd;

	fd = open("resources/42.obj", O_RDONLY);
	o->listvertex = get_listvertex(fd);
	get_buffvertex(o);
	fd = open("resources/42.obj", O_RDONLY);
	o->listfragment = get_listfragment(fd);
	get_bufffragment(o);
	close(fd);
}