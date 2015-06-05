/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 14:28:58 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/05 11:24:09 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		get_triangle(t_listvertex **listvertex, char **vertex, int size)
{
	int		i;

	i = 1;
	while (i < size)
	{
		listvertex_pushback(listvertex,
			ft_listvertex_new(ft_atof(vertex[i])));
		i++;
	}
}

void		get_first_triangle(t_listfragment **listfragment, char **frag,
	int size)
{
	int		i;

	i = 1;
	while (i < size)
	{
		listfragment_pushback(listfragment,
			ft_listfragment_new(ft_atoi(frag[i]) - 1));
		i++;
	}
}

void		get_second_triangle(t_listfragment **listfragment, char **frag,
	int size)
{
	int		i;

	i = 3;
	while (i < size)
	{
		listfragment_pushback(listfragment,
			ft_listfragment_new(ft_atoi(frag[i]) - 1));
		i++;
	}
	listfragment_pushback(listfragment,
			ft_listfragment_new(ft_atoi(frag[1]) - 1));
}

void		free_frag(char **frag)
{
	int		i;

	i = 0;
	while (i++ < get_size_of_split(frag))
		free(frag[i - 1]);
	free(frag);
}
