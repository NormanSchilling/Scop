/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 13:55:08 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/27 15:34:08 by nschilli         ###   ########.fr       */
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
}

void	opengl_draw(GLuint vertex_buffer)
{
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
}

void	opengl_loop(t_opengl *o)
{
	GLuint		program;
	GLuint		vertex_buffer;
	GLuint		vertex_array_id;
	GLfloat		data[] = { -1.0f, -1.0f, 0.0f,
							1.0f, -1.0f, 0.0f,
							0.0f, 1.0f, 0.0f };

	glGenVertexArrays(1, &vertex_array_id);
	glBindVertexArray(vertex_array_id);
	program = load_program();
	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data),
		data, GL_STATIC_DRAW);
	while (glfwGetKey(o->window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& !glfwWindowShouldClose(o->window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(program);
		opengl_draw(vertex_buffer);
		glfwPollEvents();
		glfwSwapBuffers(o->window);
	}
	glDeleteProgram(program);
	glfwTerminate();
}
