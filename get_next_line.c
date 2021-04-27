/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:04:00 by nedebies          #+#    #+#             */
/*   Updated: 2021/04/27 14:32:39 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	adjust_content(int fd, char **line, char **opened_files)
{
	int		check;

	check = ft_strchr(*line, '\n');
	free(opened_files[fd]);
	if (check != -1)
	{
		opened_files[fd] = ft_strdup(*line + check + 1);
		if (!opened_files[fd])
			return (-1);
		*line = ft_substr(*line, 0, check);
		if (!*line)
			return (-1);
	}
	else
	{
		opened_files[fd] = NULL;
		return (0);
	}
	return (1);
}

int	read_line(int fd, char **line, char **opened_files)
{
	int		ret;
	char	*buffer;
	int		check;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	*line = ft_strdup(opened_files[fd]);
	if (!*line)
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		*line = ft_strjoin(*line, buffer);
		if (!*line)
			return (-1);
		check = ft_strchr(*line, '\n');
		if (check != -1)
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (ret < 0)
		return (-1);
	return (adjust_content(fd, line, opened_files));
}

int	get_next_line(int fd, char **line)
{
	static char		*opened_files[FOPEN_MAX];

	if (fd < 0 || fd > FOPEN_MAX || !line)
		return (-1);
	if (BUFFER_SIZE < 1)
		return (-1);
	if (!opened_files[fd])
	{
		opened_files[fd] = ft_strdup("");
		if (!opened_files[fd])
			return (-1);
	}
	return (read_line(fd, line, opened_files));
}
