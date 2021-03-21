/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndebiesm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:15:56 by ndebiesm          #+#    #+#             */
/*   Updated: 2019/10/28 10:29:56 by ndebiesm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		get_next_line(int fd, char **line);
//int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *line, char *buffer);
int		ft_strchr(char *str, char c);
char	*ft_substr(char *str, int start, int size);

#endif
