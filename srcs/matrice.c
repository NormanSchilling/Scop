/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 15:35:12 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/28 14:12:42 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		matrice_fetch(float mat[4][4])
{
	t_mat	m;

	m.i = 0;
	while (m.i < 4)
	{
		m.j = 0;
		while (m.j < 4)
		{
			printf("%f  ", mat[m.j][m.i]);
			m.j++;
		}
		m.i++;
		printf("\n");
	}
	printf("\n");
}

t_mat		matrice_projection(float angle, float near_z, float far_z)
{
	t_mat		m;
	float		ratio;
	float		theta;

	ratio = WIDTH / HEIGHT;
	theta = (angle * M_PI) / 180;
	m = matrice_init();
	m.mat[0][0] = 1 / ratio * tan(theta / 2);
	m.mat[1][1] = 1 / tan(theta / 2);
	m.mat[2][2] = (- near_z - far_z) / (near_z - far_z);
	m.mat[2][3] = 1;
	m.mat[3][2] = (2 * near_z * far_z) / (near_z - far_z);
	m.mat[3][3] = 0;

	return (m);
}

t_mat		matrice_scale(t_vec v)
{
	t_mat	m;

	m = matrice_init();
	m.mat[0][0] = v.x;
	m.mat[1][1] = v.y;
	m.mat[2][2] = v.z;

	return (m);
}

t_mat		matrice_translate(t_vec v)
{
	t_mat	m;

	m = matrice_init();
	m.mat[3][0] = v.x;
	m.mat[3][1] = v.y;
	m.mat[3][2] = v.z;

	return (m);
}

t_mat		matrice_init()
{
	t_mat	m;

	m.i = 0;
	while (m.i < 4)
	{
		m.j = 0;
		while (m.j < 4)
		{
			if (m.i == m.j)
				m.mat[m.i][m.j] = 1;
			else
				m.mat[m.i][m.j] = 0;
			m.j++;
		}
		m.i++;
	}
	return (m);
}
