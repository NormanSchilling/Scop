/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 13:51:54 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/01 15:17:23 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		parser_vertex(int fd)
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
	printf("%d\n", listvertex_size(listvertex));
}

void		parser_fragment(int fd)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'f')
		{
			free(line);
		}
	}
}

void		parser()
{
	int		fd;

	fd = open("resources/42.obj", O_RDONLY);
	parser_vertex(fd);
	fd = open("resources/42.obj", O_RDONLY);
	parser_fragment(fd);
	close(fd);
}