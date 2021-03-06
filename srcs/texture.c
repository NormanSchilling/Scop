/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 16:20:26 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/04 16:03:15 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_texture(t_opengl *o)
{
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &(o->tex.tex));
	glBindTexture(GL_TEXTURE_2D, o->tex.tex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, o->tex.width, o->tex.height, 0,
		GL_BGR, GL_UNSIGNED_BYTE, o->tex.buff_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
}

int		check_error_load_texture(t_opengl *o, FILE *file)
{
	if (!file)
	{
		ft_putstr("Image could not be opened\n");
		return (1);
	}
	if (fread(o->tex.header, 1, 54, file) != 54)
	{
		ft_putstr("Not a correct JPG file\n");
		return (1);
	}
	if (o->tex.header[0] != 'B' || o->tex.header[1] != 'M')
	{
		ft_putstr("Not a correct BMP file\n");
		return (1);
	}
	return (0);
}

void	load_texture(t_opengl *o)
{
	FILE			*file;

	file = fopen("resources/cat.bmp", "rb");
	if (check_error_load_texture(o, file) == 1)
		exit(-1);
	o->tex.data_pos = *(int*)&(o->tex.header[0x0A]);
	o->tex.image_size = *(int*)&(o->tex.header[0x22]);
	o->tex.width = *(int*)&(o->tex.header[0x12]);
	o->tex.height = *(int*)&(o->tex.header[0x16]);
	if (o->tex.image_size == 0)
		o->tex.image_size = o->tex.width * o->tex.height * 3;
	if (o->tex.data_pos == 0)
		o->tex.data_pos = 54;
	o->tex.buff_texture = (unsigned char*)malloc(o->tex.image_size);
	if (o->tex.buff_texture == NULL)
	{
		ft_putstr("Error malloc buff_texture\n");
		exit(-1);
	}
	fread(o->tex.buff_texture, 1, o->tex.image_size, file);
	fclose(file);
}
