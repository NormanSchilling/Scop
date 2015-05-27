/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 13:55:08 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/27 12:26:17 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	opengl_init(t_opengl *o)
{
	if (!glfwInit())
	{
		ft_putendl("Error : Failed initialize GLFW.");
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	o->window = glfwCreateWindow( WIDTH, HEIGHT, "Scop", NULL, NULL);
	if (o->window == NULL)
	{
		ft_putendl("Error : Window with opengl can't be null.");
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(o->window);
	glfwSwapInterval(1);
	glfwSetInputMode(o->window, GLFW_STICKY_KEYS, GL_TRUE);
}

void	opengl_loop(t_opengl *o)
{
	GLuint		program;
	GLuint		shader_vertex;
	GLuint		shader_frag;

	while (glfwGetKey(o->window, GLFW_KEY_ESCAPE) != GLFW_PRESS 
		&& glfwWindowShouldClose(o->window) == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity( );

		program = glCreateProgram();
		shader_vertex = load_shader(GL_VERTEX_SHADER, "shaders/shader_first.vert");
		shader_frag = load_shader(GL_VERTEX_SHADER, "shaders/shader_first.frag");
		program = load_program(shader_vertex, shader_frag);

		glUseProgram(program);

		glDeleteShader(shader_vertex);
		glDeleteShader(shader_frag);

		glFlush();
		glfwSwapBuffers(o->window);
		glfwPollEvents();
	}

	glUseProgram(0);
	// glDetachShader(program, shader);
	glDeleteProgram(program);
	
	glfwTerminate();
}
