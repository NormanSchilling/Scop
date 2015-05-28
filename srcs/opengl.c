/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 13:55:08 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/28 14:19:50 by nschilli         ###   ########.fr       */
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
	GLuint		m_projection_location;
	GLuint		m_view_location;
	GLuint		m_model_location;
	t_mat		m_projection;
	t_mat		m_view;
	t_mat		m_model;
	GLfloat		data[] = { -1.0f, -1.0f, 0.0f,
							1.0f, -1.0f, 0.0f,
							0.0f, 1.0f, 0.0f };

	glGenVertexArrays(1, &vertex_array_id);
	glBindVertexArray(vertex_array_id);
	m_projection = matrice_projection(65.f, 0.1, 100.f);
	matrice_fetch(m_projection.mat);
	m_view = matrice_init();
	m_model = matrice_init();
	program = load_program();
	m_projection_location = glGetUniformLocation(program, "m_projection");
	m_view_location = glGetUniformLocation(program, "m_view");
	m_model_location = glGetUniformLocation(program, "m_model");
	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data),
		data, GL_STATIC_DRAW);
	while (glfwGetKey(o->window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& !glfwWindowShouldClose(o->window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(program);
		glUniformMatrix4fv(m_projection_location, 1, GL_FALSE, &m_projection.mat[4][4]);
		glUniformMatrix4fv(m_view_location, 1, GL_FALSE, &m_view.mat[4][4]);
		glUniformMatrix4fv(m_model_location, 1, GL_FALSE, &m_model.mat[4][4]);
		opengl_draw(vertex_buffer);
		glfwPollEvents();
		glfwSwapBuffers(o->window);
	}
	glDeleteProgram(program);
	glfwTerminate();
}
