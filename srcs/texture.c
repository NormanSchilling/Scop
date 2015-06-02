/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 16:20:26 by nschilli          #+#    #+#             */
/*   Updated: 2015/06/02 16:33:00 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

Gluint		load_texture(void)
{
	unsigned char	header[10];
	unsigned int	data_pos;
	unsigned int	width;
	unsigned int	height; 
	unsigned int	image_size;
	unsigned char	*data;
	FILE			*file;

	file = fopen("resources/texture_space.jpg","rb"); 
	if (!file)
	{
		ft_putstr("Image could not be opened\n");
		return (0);
	}
	if (fread(header, 1, 10, file) != 10)
	{
    	printf("Not a correct JPG file\n"); 
		return (0); 
	}
}