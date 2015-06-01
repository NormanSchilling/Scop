/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_multiplication.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 11:55:21 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/01 13:18:51 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float		matrice_multiplication_result(t_mat *m, t_mat m_one, t_mat m_two)
{
	int		index;
	float	result;

	result = 0.0f;
	index = 0;
	m_one.i = m->i;
	m_two.j = m->j;
	while (index < 4)
	{
		result = result + m_one.mat[m_one.i][index] *
			m_two.mat[index][m_two.j];
		index++;
	}
	return (result);
}

t_mat		matrice_multiplication(t_mat m_one, t_mat m_two)
{
	t_mat	m;

	m.i = 0;
	while ( m.i < 4)
	{
		m.j = 0;
		while ( m.j < 4 )
		{
			m.mat[m.i][m.j] = matrice_multiplication_result(&m, m_one, m_two);
			m.j++;
		}
		m.i++;
	}

	return (m);
}