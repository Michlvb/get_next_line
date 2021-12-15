/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlammert <mlammert@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 16:51:20 by mlammert      #+#    #+#                 */
/*   Updated: 2021/12/14 21:27:46 by mlammert      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <stdio.h>

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (((char *)s));
		s++;
	}
	return (s);
}

int	check_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*output(char **line)
{
	char	*res;
	char	*old;
	int		len;

	res = ft_strdup(*line);
	len = ft_strlen(ft_strchr(*line, '\n') + 1);
	old = ft_substr(*line, check_newline(*line) + 1, len);
	free(*line);
	*line = old;
	return (res);
}

char	*free_all(char **line)
{
	char	*res;

	if (!line)
		return (NULL);
	if (*line && check_newline(*line) >= 0)
		return (output(line));
	else if (ft_strchr(*line, '\0') && **line)
		res = ft_strdup(*line);
	else
		res = NULL;
	free(*line);
	*line = NULL;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		buf[BUFFER_SIZE + 1];
	int			nbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nbytes = read(fd, buf, BUFFER_SIZE);
	while (nbytes > 0)
	{
		buf[nbytes] = '\0';
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
		if (check_newline(line) >= 0)
		{
			return (output(&line));
		}
		nbytes = read(fd, buf, BUFFER_SIZE);
	}
	if (nbytes < 0)
		return (NULL);
	buf[nbytes] = '\0';
	line = ft_strjoin(line, buf);
	return (free_all(&line));
}
