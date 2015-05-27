/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 11:34:45 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/27 12:20:59 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			check_program_error(GLuint program, GLint compile_status)
{
	GLint		logsize;
	char		*log_program;

	log_program = NULL;
	glGetProgramiv(program, GL_COMPILE_STATUS, &compile_status);
	if (compile_status != GL_TRUE)
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
	GLint		compile_status;


	compile_status = GL_TRUE;
	program = glCreateProgram();
	glAttachShader(program, shader_vertex);
	glAttachShader(program, shader_frag);
	glLinkProgram(program);
	if (check_program_error(program, compile_status) == 1)
	{
		glDetachShader(program, shader);
		glDeleteProgram(program);
		exit(-1);
	}
	return (program);
}