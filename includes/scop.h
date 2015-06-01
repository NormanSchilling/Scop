/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 11:28:38 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/01 15:37:28 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# define GLFW_INCLUDE_GLCOREARB
# define WIDTH 1000.0f
# define HEIGHT 1000.0f

# include <GLFW/glfw3.h>
# include "../libft/libft.h"

# include "matrice.h"
# include "get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct			s_listvertex
{
	float				point;
	struct s_listvertex	*next;
}						t_listvertex;

typedef struct			s_opengl
{
	GLFWwindow			*window;
	GLuint				m_projection_location;
	GLuint				m_view_location;
	GLuint				m_model_location;
	GLuint				program;
	GLuint				vertex_buffer;
	GLuint				vertex_array_id;
	t_mat				m_projection;
	t_mat				m_view;
	t_mat				m_model;
	t_mat				m_rotate;
	t_listvertex		*listvertex;
	float				*buffvertex;
}						t_opengl;

int				listvertex_size(t_listvertex *beginlist);
void			listvertex_pushback(t_listvertex **beginlist,
	t_listvertex *newlist);
t_listvertex	*ft_listvertex_new(float point);

float			*get_buffvertex(t_opengl *o);
t_listvertex	*get_listvertex(int fd);
void			parser(t_opengl *o);

void			opengl_init(t_opengl *o);
void			opengl_draw(GLuint vertex_buffer);
void			opengl_before_loop(t_opengl *o);
void			opengl_loop(t_opengl *o);

int				check_shader_error(GLuint shader,
					GLint	compile_status, char *filename);
GLuint			load_shader(GLenum type, char *filename);
char			*load_file(char *filename);

int				check_program_error(GLuint program, GLint link_status);
GLuint			load_program();

#endif
