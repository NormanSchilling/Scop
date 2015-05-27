/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 15:40:10 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/27 17:18:08 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct		s_mat
{
	float			mat[4][4];
	int				i;
	int				j;
}					t_mat;

typedef struct		s_vec
{
	float			x;
	float			y;
	float			z;
}					t_vec;

void		matrice_fetch(float mat[4][4]);
t_mat		matrice_scale(t_vec v);
t_mat		matrice_translate(t_vec v);
void		matrice_rotate_calc(t_vec v, t_mat *m, float angle);
t_mat		matrice_rotate(t_vec v, float angle);
t_mat		matrice_init();