/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:04:00 by nedebies          #+#    #+#             */
/*   Updated: 2021/08/02 02:54:16 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_fill_static(char **opened_file, char **temp, char **buffer)
{
	if (!*opened_file)
		*opened_file = ft_strdup(*buffer);
	else
	{
		*temp = ft_strdup(*opened_file);
		free(*opened_file);
		*opened_file = ft_strjoin(*temp, *buffer);
		free(*temp);
	}
}

static char	*ft_adjust_content(char **opened_file, size_t *i_new_line)
{
	int		i;
	char	*temp;
	char	*line;

	i = 0;
	line = NULL;
	if (!*opened_file)
		return (NULL);
	temp = ft_strdup(*opened_file);
	if (ft_strchr(&*opened_file, &*i_new_line))
	{
		line = ft_substr(*opened_file, 0, *i_new_line + 1);
		free(*opened_file);
		*opened_file = ft_substr(temp, *i_new_line + 1, ft_strlen(temp));
	}
	else
	{
		i = ft_strlen(temp);
		if (i > 0)
			line = ft_substr(temp, 0, i);
		free(*opened_file);
		*opened_file = NULL;
	}
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	size_t		ret;
	size_t		i_new_line;
	static char	*opened_file;
	char		*buffer;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) != 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	ret = read(fd, buffer, BUFFER_SIZE);
	i_new_line = 0;
	while (ret > 0)
	{
		buffer[ret] = '\0';
		ft_fill_static(&opened_file, &temp, &buffer);
		if (ft_strchr(&opened_file, &i_new_line))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}	
	free(buffer);
	return (ft_adjust_content(&opened_file, &i_new_line));
}
