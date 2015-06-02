/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 14:28:58 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/02 14:57:17 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

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
		printf("%d ", ft_atoi(frag[i]));
		listfragment_pushback(listfragment,
			ft_listfragment_new(ft_atoi(frag[i]) - 1));
		i++;
	}
	printf("%d\n", ft_atoi(frag[1]));
	listfragment_pushback(listfragment,
			ft_listfragment_new(ft_atoi(frag[1]) - 1));
}
