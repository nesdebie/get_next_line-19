/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:52:36 by nesdebie          #+#    #+#             */
/*   Updated: 2023/04/14 12:08:07 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include "get_next_line.h"

static	char *ft_free(char *buffer)
{
	if (buffer)
		free(buffer);
	return (0);
}

static char	*ft_new_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	j = ft_strlen(buffer) - i;
	line = ft_calloc((j + 1), sizeof(char));
	if (!line)
		return (ft_free(buffer));
	i++;
	j = 0;
	while (buffer[i])
	{
		line[j] = buffer[i];
		j++;
		i++;
	}
	free(buffer);
	return (line);
}

static char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (ft_free(buffer));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*read_file(int fd, char *res)
{
	char	*tmp;
	int		is_read;

	if (!res)
		res = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (ft_free(res));
	is_read = 1;
	while (is_read > 0)
	{
		is_read = read(fd, tmp, BUFFER_SIZE);
		if (is_read == -1)
		{
			free(tmp);
			return (ft_free(res));
		}
		tmp[is_read] = 0;
		res = ft_strjoin(res, tmp);
		if (!res)
			return(ft_free(res));
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_new_buffer(buffer[fd]);
	return (line);
}
