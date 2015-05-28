/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 11:28:38 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/28 14:44:37 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# define GLFW_INCLUDE_GLCOREARB
# define BUFF_SIZE 128
# define WIDTH 1000.f
# define HEIGHT 700.f

# include <GLFW/glfw3.h>
# include "../libft/libft.h"

# include "matrice.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_opengl
{
	GLFWwindow		*window;
}					t_opengl;

int				get_next_line(const int fd, char **line);

void			opengl_init(t_opengl *o);
void			opengl_draw(GLuint vertex_buffer);
void			opengl_loop(t_opengl *o);

int				check_shader_error(GLuint shader,
					GLint	compile_status, char *filename);
GLuint			load_shader(GLenum type, char *filename);
char			*load_file(char *filename);

int				check_program_error(GLuint program, GLint link_status);
GLuint			load_program();

#endif
