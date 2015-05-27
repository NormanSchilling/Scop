/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 15:35:12 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/27 17:32:38 by nschilli         ###   ########.fr       */
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
			ft_putnbr(mat[m.j][m.i]);
			ft_putstr("  ");
			m.j++;
		}
		ft_putstr("\n");
		m.i++;
	}
	ft_putstr("\n");
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

void		matrice_rotate_calc(t_vec v, t_mat *m, float angle)
{
	float	theta;

	theta = (angle * M_PI) / 180;
	if (m->i == 0 && m->j == 0)
		m->mat[m->i][m->j] = v.x * v.x * (1 - cos(theta)) + cos(theta);
	if (m->i == 1 && m->j == 0)
		m->mat[m->i][m->j] = v.x * v.y * (1 - cos(theta)) + v.y * sin(theta);
	if (m->i == 2 && m->j == 0)
		m->mat[m->i][m->j] = v.x * v.z * (1 - cos(theta)) - v.z * sin(theta);

	if (m->i == 0 && m->j == 1)
		m->mat[m->i][m->j] = v.x * v.y * (1 - cos(theta)) - v.z * sin(theta);
	if (m->i == 1 && m->j == 1)
		m->mat[m->i][m->j] = v.y * v.y * (1 - cos(theta)) + cos(theta);
	if (m->i == 2 && m->j == 1)
		m->mat[m->i][m->j] = v.y * v.z * (1 - cos(theta)) + v.x * sin(theta);

	if (m->i == 0 && m->j == 2)
		m->mat[m->i][m->j] = v.x * v.z * (1 - cos(theta)) + v.y * sin(theta);
	if (m->i == 1 && m->j == 2)
		m->mat[m->i][m->j] = v.y * v.z * (1 - cos(theta)) - v.x * sin(theta);
	if (m->i == 2 && m->j == 2)
		m->mat[m->i][m->j] = v.z * v.z * (1 - cos(theta)) + cos(theta);
}

t_mat		matrice_rotate(t_vec v, float angle)
{
	t_mat	m;

	m.i = 0;
	while (m.i < 4)
	{
		m.j = 0;
		while (m.j < 4)
		{
			if (m.i == 3 && m.j == 3)
				m.mat[m.i][m.j] = 1;
			else
				m.mat[m.i][m.j] = 0;
			matrice_rotate_calc(v, &m, angle);
			m.j++;
		}
		m.i++;
	}
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