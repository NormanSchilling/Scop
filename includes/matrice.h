/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 15:40:10 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/28 16:27:32 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct		s_mat
{
	float			mat[4][4];
	int				i;
	int				j;
}					t_mat;

t_mat		matrice_rotate_x(float angle);
t_mat		matrice_rotate_y(float angle);
t_mat		matrice_rotate_z(float angle);

void		matrice_fetch(float mat[4][4]);
t_mat		matrice_projection(float angle, float near_z, float far_z);
t_mat		matrice_scale(float x, float y, float z);
t_mat		matrice_translate(float x, float y, float z);
t_mat		matrice_init();
