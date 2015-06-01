/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 13:55:08 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/01 17:47:26 by nschilli         ###   ########.fr       */
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

void	opengl_draw(t_opengl *o)
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, o->vertex_buffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o->element_buffer);
	glDrawElements(GL_TRIANGLES, listfragment_size(o->listfragment) * sizeof(GLint),
		GL_UNSIGNED_INT, (void*)0);
	glDisableVertexAttribArray(0);


}

void	opengl_before_loop(t_opengl *o)
{
	GLfloat		data[] = { -0.5f, -0.5f, 0.0f,
							0.5f, -0.5f, 0.0f,
							0.0f, 0.5f, 0.0f };
	GLint		data_i[] = { 0, 1, 2 };

	glGenVertexArrays(1, &(o->vertex_array_id));
	glBindVertexArray(o->vertex_array_id);
	o->m_projection = matrice_projection(60.0f, 1.0f, 100.0f);
	o->m_view = matrice_init();
	o->m_view.mat[3][2] = 10;
	o->m_model = matrice_init();
	o->m_rotate = matrice_rotate_y(10);
	o->program = load_program();
	o->m_view_location = glGetUniformLocation(o->program, "view");
	o->m_model_location = glGetUniformLocation(o->program, "model");
	o->m_projection_location = glGetUniformLocation(o->program, "projection");

	glGenBuffers(1, &(o->vertex_buffer));
	glBindBuffer(GL_ARRAY_BUFFER, o->vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data),
		data, GL_STATIC_DRAW);

	glGenBuffers(1, &(o->element_buffer));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o->element_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data_i),
		data_i, GL_STATIC_DRAW);
}

void	opengl_loop(t_opengl *o)
{
	while (glfwGetKey(o->window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& !glfwWindowShouldClose(o->window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(o->program);
		glUniformMatrix4fv(o->m_projection_location, 1, GL_FALSE,
			&(o->m_projection.mat[0][0]));
		glUniformMatrix4fv(o->m_view_location, 1, GL_FALSE,
			&(o->m_view.mat[0][0]));
		o->m_model = matrice_multiplication(o->m_model, o->m_rotate);
		glUniformMatrix4fv(o->m_model_location, 1, GL_FALSE,
			&(o->m_model.mat[0][0]));
		opengl_draw(o);
		glfwPollEvents();
		glfwSwapBuffers(o->window);
	}
	glDeleteProgram(o->program);
	glfwTerminate();
}
