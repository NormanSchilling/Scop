/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 11:28:38 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/26 17:00:41 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <GLFW/glfw3.h>
# include <OpenGL/gl.h>
# include "../libft/libft.h"

# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 128
# define WIDTH 1000
# define HEIGHT 700

typedef struct		s_opengl
{
	GLFWwindow		*window;
}					t_opengl;

int				get_next_line(const int fd, char **line);

void			opengl_init(t_opengl *o);
void			opengl_loop(t_opengl *o);

int				check_shader_error(GLuint shader, GLint	compile_status);
GLuint			load_shader(GLenum type, char *filename);	
char			*stock_file(FILE *fp, long size);
char			*load_file(char *filename);

#endif