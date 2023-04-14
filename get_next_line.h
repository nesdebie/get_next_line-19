/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:53:20 by nesdebie          #+#    #+#             */
/*   Updated: 2023/04/14 10:28:02 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char const *str, int c);

char	*get_next_line(int fd);
#endif