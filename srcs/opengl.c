/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 13:55:08 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/05 13:50:08 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void key_callback(GLFWwindow *window, int key, int scancode,
	int action, int mods)
{
	t_opengl	*o;
	GLint		render_mode;
	static int	count = 0;

	o = get_opengl();
	(void)scancode;
	(void)mods;
	(void)window;
	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
	{
		if (count == 0)
			count++;
		else
			count--;
		render_mode = glGetUniformLocation(o->program, "renderMode");
		glUniform1i(render_mode, count);
	}
}

void		opengl_init(t_opengl *o)
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
	o->window = glfwCreateWindow(WIDTH, HEIGHT, "Scop", NULL, NULL);
	if (o->window == NULL)
	{
		ft_putendl("Error : Window with opengl can't be null.");
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(o->window);
	glfwSwapInterval(1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

void		opengl_draw(t_opengl *o)
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, o->vertex_buffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, o->normal_buffer);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o->element_buffer);
	glDrawElements(GL_TRIANGLES, listfragment_size(o->listfragment)
		* sizeof(int), GL_UNSIGNED_INT, (void*)0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void		opengl_before_loop(t_opengl *o)
{
	glGenVertexArrays(1, &(o->vertex_array_id));
	glBindVertexArray(o->vertex_array_id);
	o->m_projection = matrice_projection(60.0f, 1.0f, 100.0f);
	o->m_view = matrice_init();
	o->m_view.mat[3][2] = 10;
	o->m_view.mat[3][1] = -3;
	o->m_model = matrice_init();
	o->m_rotate = matrice_rotate_y(3);
	o->program = load_program();
	o->m_view_location = glGetUniformLocation(o->program, "view");
	o->m_model_location = glGetUniformLocation(o->program, "model");
	o->m_projection_location = glGetUniformLocation(o->program, "projection");
	glGenBuffers(1, &(o->vertex_buffer));
	glBindBuffer(GL_ARRAY_BUFFER, o->vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER,
		listvertex_size(o->listvertex) * sizeof(float),
		o->buffvertex, GL_STATIC_DRAW);
	glGenBuffers(1, &(o->element_buffer));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o->element_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		listfragment_size(o->listfragment) * sizeof(int),
		o->bufffragment, GL_STATIC_DRAW);

	glGenBuffers(1, &o->normal_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, o->normal_buffer);
	glBufferData(GL_ARRAY_BUFFER,
		listvertex_size(o->listvertex) * sizeof(float),
		&o->buffnormal[0].x, GL_STATIC_DRAW);

	init_texture(o);
}

void		opengl_loop(t_opengl *o)
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
		glfwSetKeyCallback(o->window, key_callback);
		opengl_draw(o);
		glfwPollEvents();
		glfwSwapBuffers(o->window);
	}
	glDeleteProgram(o->program);
	glfwTerminate();
}
