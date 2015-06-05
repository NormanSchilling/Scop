/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 11:09:29 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/05 12:11:00 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_opengl	*get_opengl(void)
{
	static t_opengl		o;

	return (&o);
}

int			main(int argc, char **argv)
{
	t_opengl	*o;

	o = get_opengl();
	if (argc == 2)
	{
		load_texture(o);
		parser(o, argv[1]);
		opengl_init(o);
		opengl_before_loop(o);
		opengl_loop(o);
	}
	return (0);
}
