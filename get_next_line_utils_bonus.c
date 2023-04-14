/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:53:06 by nesdebie          #+#    #+#             */
/*   Updated: 2023/04/14 11:14:08 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char const *str, int c)
{
	char	my_c;

	my_c = (char)c;
	while (*str)
	{
		if (*str == my_c)
			return ((char *)str);
		str++;
	}
	if (!my_c)
		return ((char *)str);
	return (NULL);
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)str++ = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	range;

	range = count * size;
	if (size != 0 && (count != range / size))
		return (0);
	if (range == 0)
		range = 1;
	ptr = malloc(range);
	if (!ptr)
		return (0);
	ft_bzero(ptr, range);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	j = 0;
	i = ft_strlen(s1);
	result = (char *)malloc((i + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (0);
	while (s1[j])
	{
		result[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		result[j] = s2[i];
		i++;
		j++;
	}
	result[j] = 0;
	free(s1);
	return (result);
}
