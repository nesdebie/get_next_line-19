/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:16:23 by nedebies          #+#    #+#             */
/*   Updated: 2021/08/02 02:54:03 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	str = 0;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = start;
	j = 0;
	str = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] && (j < len))
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strchr(char **str, size_t *c)
{
	size_t	i;

	i = 0;
	if (!*str)
		return (0);
	while ((*str)[i])
	{
		if ((*str)[i] == '\n')
		{
			*c = i;
			return (1);
		}
		i++;
	}
	return (0);
}