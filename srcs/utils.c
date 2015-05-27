/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 16:02:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/27 12:29:51 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			check_shader_error(GLuint shader,
	GLint	compile_status, char *filename)
{
	GLint		logsize;
	char		*log_shader;

	log_shader = NULL;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);
	if (compile_status != GL_TRUE)
	{
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logsize);
		log_shader = (char*)malloc(sizeof(logsize) + 1);
		if (log_shader == NULL)
		{
			ft_putstr("Error : Probleme d'allocation de memoire");
			exit(-1);
		}
		ft_memset(log_shader, '\0', logsize + 1);
		glGetShaderInfoLog(shader, logsize, &logsize, log_shader);
		ft_putstr("Error : impossible de compiler le shader ");
		ft_putendl(filename);
		ft_putendl(log_shader);
		free(log_shader);
		return (1);
	}
	return (0);
}

GLuint		load_shader(GLenum type, char *filename)
{
	GLuint			shader;
	GLint			compile_status;
	const char		*src;

	compile_status = GL_TRUE;
	shader = glCreateShader(type);
	if (glIsShader(shader) == 0)
		exit(-1);
	src = load_file(filename);
	if (src == NULL)
		exit(-1);
	glShaderSource(shader, 1, &src, NULL);
	glCompileShader(shader);
	free((void*)src);

	if (check_shader_error(shader, compile_status, filename) == 1)
	{
		glDeleteShader(shader);
		exit(-1);
	}
	return (shader);
}

char		*stock_file(FILE *fp, long size)
{
	char	*src;
	long	i;

	src = (char*)malloc(sizeof(size) + 1);
	if (src == NULL)
	{
		fclose(fp);
		ft_putstr("Error : Probleme d'allocation de memoire");
		return NULL;
	}
	i = 0;
	while (i < size)
	{
		src[i] = fgetc(fp);
		i++;
	}
	src[size] = '\0';

	return (src);
}

char		*load_file(char *filename)
{
	char	*src;
	FILE	*fp;
	long	size;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		ft_putstr("Error : Impossible d'ouvrir le fichier ");
		ft_putendl(filename);
		return NULL;
	}

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	src = stock_file(fp, size);
	fclose(fp);

	return (src);
}