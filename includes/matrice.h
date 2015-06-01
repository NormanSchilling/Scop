/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 15:40:10 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/01 15:11:32 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
# define MATRICE_H

typedef struct		s_mat
{
	float			mat[4][4];
	int				i;
	int				j;
}					t_mat;

float		matrice_multiplication_result(t_mat *m, t_mat m_one, t_mat m_two);
t_mat		matrice_multiplication(t_mat m_one, t_mat m_two);

t_mat		matrice_rotate_x(float angle);
t_mat		matrice_rotate_y(float angle);
t_mat		matrice_rotate_z(float angle);

void		matrice_fetch(float mat[4][4]);
t_mat		matrice_projection(float angle, float near_z, float far_z);
t_mat		matrice_scale(float x, float y, float z);
t_mat		matrice_translate(float x, float y, float z);
t_mat		matrice_init();

#endif