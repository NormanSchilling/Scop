/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 11:09:29 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/27 17:05:10 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		main(void)
{
	// t_opengl	o;
	t_mat		m;
	t_vec		v;

	m = matrice_init();
	matrice_fetch(m.mat);

	v.x = 5.f;
	v.y = 6.f;
	v.z = 7.f;
	m = matrice_scale(v);
	matrice_fetch(m.mat);

	v.x = 2.f;
	v.y = 6.f;
	v.z = 8.f;
	m = matrice_translate(v);
	matrice_fetch(m.mat);

	v.x = 3.f;
	v.y = 5.f;
	v.z = 7.f;
	m = matrice_rotate(v, 200);
	matrice_fetch(m.mat);

	// opengl_init(&o);
	// opengl_loop(&o);

	return (0);
}
