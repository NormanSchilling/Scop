/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 11:09:29 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/04 14:17:21 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		main(void)
{
	t_opengl	o;

	load_texture(&o);
	parser(&o);
	opengl_init(&o);
	opengl_before_loop(&o);
	opengl_loop(&o);
	return (0);
}
