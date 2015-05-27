/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 11:34:45 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/27 14:59:43 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			check_program_error(GLuint program, GLint link_status)
{
	GLint		logsize;
	char		*log_program;

	log_program = NULL;
	glGetProgramiv(program, GL_LINK_STATUS, &link_status);
	if (link_status != GL_TRUE)
	{
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logsize);
		log_program = (char*)malloc(sizeof(logsize) + 1);
		if (log_program == NULL)
		{
			ft_putstr("Error : Probleme d'allocation de memoire");
			exit(1);
		}
		ft_memset(log_program, '\0', logsize + 1);
		glGetProgramInfoLog(program, logsize, &logsize, log_program);
		ft_putendl("Error : impossible de link le program");
		ft_putendl(log_program);
		free(log_program);
		return (1);
	}
	return (0);
}

GLuint		load_program(GLuint shader_vertex, GLuint shader_frag)
{
	GLuint		program;
	GLint		link_status;
	GLuint		shader_vertex;
	GLuint		shader_frag;

	link_status = GL_TRUE;
	shader_vertex = load_shader(GL_VERTEX_SHADER, "shaders/shader_first.vert");
	shader_frag = load_shader(GL_FRAGMENT_SHADER, "shaders/shader_first.frag");
	program = glCreateProgram();
	glAttachShader(program, shader_vertex);
	glAttachShader(program, shader_frag);
	glLinkProgram(program);
	if (check_program_error(program, link_status) == 1)
	{
		glDetachShader(program, shader_vertex);
		glDetachShader(program, shader_frag);
		glDeleteProgram(program);
		exit(-1);
	}
	glDeleteShader(shader_vertex);
	glDeleteShader(shader_frag);
	return (program);
}
