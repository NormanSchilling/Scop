/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 11:28:38 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/02 14:50:07 by nschilli         ###   ########.fr       */
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

typedef struct				s_listvertex
{
	float					point;
	struct s_listvertex		*next;
}							t_listvertex;

typedef struct				s_listfragment
{
	int						point;
	struct s_listfragment	*next;
}							t_listfragment;

typedef struct				s_opengl
{
	GLFWwindow				*window;
	GLuint					m_projection_location;
	GLuint					m_view_location;
	GLuint					m_model_location;
	GLuint					program;
	GLuint					vertex_buffer;
	GLuint					element_buffer;
	GLuint					vertex_array_id;
	t_mat					m_projection;
	t_mat					m_view;
	t_mat					m_model;
	t_mat					m_rotate;
	t_listvertex			*listvertex;
	GLfloat					*buffvertex;
	t_listfragment			*listfragment;
	GLint					*bufffragment;
}							t_opengl;

void		get_first_triangle(t_listfragment **listfragment,
	char **frag, int size);
void		get_second_triangle(t_listfragment **listfragment,
	char **frag, int size);


int				listfragment_size(t_listfragment *beginlist);
void			listfragment_pushback(t_listfragment **beginlist,
	t_listfragment *newlist);
t_listfragment	*ft_listfragment_new(float point);

void			listvertex_fetch(t_listvertex *listvertex);
int				listvertex_size(t_listvertex *beginlist);
void			listvertex_pushback(t_listvertex **beginlist,
	t_listvertex *newlist);
t_listvertex	*ft_listvertex_new(float point);

t_listvertex	*get_listvertex(int fd);
t_listfragment	*get_listfragment(int fd);
void			get_buffvertex(t_opengl *o);
void			get_bufffragment(t_opengl *o);
void			parser(t_opengl *o);

void			opengl_init(t_opengl *o);
void			opengl_draw(t_opengl *o);
void			opengl_before_loop(t_opengl *o);
void			opengl_loop(t_opengl *o);

int				get_size_of_split(char **split);
int				check_shader_error(GLuint shader,
					GLint	compile_status, char *filename);
GLuint			load_shader(GLenum type, char *filename);
char			*load_file(char *filename);

int				check_program_error(GLuint program, GLint link_status);
GLuint			load_program();

#endif
