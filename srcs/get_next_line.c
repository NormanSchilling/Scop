/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 13:39:36 by nschilli          #+#    #+#             */
/*   Updated: 2015/05/26 11:36:16 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int		ft_checkline(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char		*ft_fillstr(char *str, int n)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (ft_strlen(str) - n) + 1);
	while (str[n])
		s[i++] = str[n++];
	s[i] = '\0';
	free(str);
	return (s);
}

static char		*ft_get_line(char *str, int n)
{
	int		i;
	char	*line;

	i = 0;
	line = (char *)malloc(sizeof(char) * n + 1);
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int				get_next_line(const int fd, char **line)
{
	static	char	*str = "";
	static	int		ret = -1;
	char			buf[BUFF_SIZE + 1];

	while (ft_checkline(str) == -1 && ret != 0 && ret != -2)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	if (ret != 0 && ret != -2)
	{
		line[0] = ft_get_line(str, ft_checkline(str));
		str = ft_fillstr(str, ft_checkline(str) + 1);
		return (1);
	}
	else if (ret == 0)
	{
		line[0] = ft_get_line(str, ft_strlen(str));
		ret = -2;
		return (1);
	}
	else if (ret == -2)
		return (0);
	return (-1);
}
