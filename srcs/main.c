/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 11:09:29 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/01 17:54:18 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		main(void)
{
	t_opengl	o;

	parser(&o);

	// int i = 0;
	// while (i < listvertex_size(o.listvertex) )
	// {
	// 	printf("%f\n", o.buffvertex[i]);
	// 	i++;
	// }

	// printf("||||||||||||||||||||||||||||||||||||||||\n");

	// i = 0;
	// while (i < listfragment_size(o.listfragment) )
	// {
	// 	printf("%d\n", o.bufffragment[i]);
	// 	i++;
	// }

	opengl_init(&o);
	opengl_before_loop(&o);
	opengl_loop(&o);

	return (0);
}
