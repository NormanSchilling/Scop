/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 11:10:54 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/28 13:07:32 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat		matrice_rotate_x(float angle)
{
	t_mat	m;
	float	theta;

	m = matrice_init();
	theta = (angle * M_PI) / 180;
	m.mat[1][1] = cos(theta);
	m.mat[1][2] = sin(theta);
	m.mat[2][1] = - sin(theta);
	m.mat[2][2] = cos(theta);

	return (m);
}

t_mat		matrice_rotate_y(float angle)
{
	t_mat	m;
	float	theta;

	m = matrice_init();
	theta = (angle * M_PI) / 180;
	m.mat[0][0] = cos(theta);
	m.mat[0][2] = - sin(theta);
	m.mat[2][0] = sin(theta);
	m.mat[2][2] = cos(theta);

	return (m);
}

t_mat		matrice_rotate_z(float angle)
{
	t_mat	m;
	float	theta;

	m = matrice_init();
	theta = (angle * M_PI) / 180;
	m.mat[0][0] = cos(theta);
	m.mat[0][1] = sin(theta);
	m.mat[1][0] = - sin(theta);
	m.mat[2][2] = cos(theta);

	return (m);
}
