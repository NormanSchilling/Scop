/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 16:02:14 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/02 16:05:59 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			get_size_of_split(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int			check_shader_error(GLuint shader,
	GLint compile_status, char *filename)
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
	char			*src;

	compile_status = GL_TRUE;
	shader = glCreateShader(type);
	if (glIsShader(shader) == 0)
		exit(-1);
	src = load_file(filename);
	if (src == NULL)
		exit(-1);
	glShaderSource(shader, 1, (const char*const*)&src, NULL);
	glCompileShader(shader);
	free(src);
	if (check_shader_error(shader, compile_status, filename) == 1)
	{
		glDeleteShader(shader);
		exit(-1);
	}
	return (shader);
}

char		*load_file(char *filename)
{
	int		fd;
	char	buff[1024];
	char	*content;
	char	*tmp;

	ft_bzero(buff, 1024);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	read(fd, buff, 1024);
	content = ft_strdup(buff);
	ft_bzero(buff, 1024);
	while (read(fd, buff, 1024) == 1024)
	{
		tmp = ft_strdup(content);
		free(content);
		content = ft_strjoin(tmp, buff);
		free(tmp);
		ft_bzero(buff, 1024);
	}
	close(fd);
	return (content);
}
