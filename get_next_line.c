#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(char *s, int c);

int	check_newline(char *line)
{
	int	i;

	if (!line)
		return (-1);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	new_len;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

char	*output_val(char **line)
{
    char    *res;
    char    *old;
    int     len;

    res = ft_strdup(*line);
    len = ft_strlen(*line + check_newline(*line) + 1);
    if (len == 0)
    {
        free(*line);
        *line = NULL;
        return (res);
    }
    old = ft_substr(*line, check_newline(*line) + 1, ft_strlen(ft_strchr(*line, '\n') + 1));
    free(*line);
    *line = old;
	return (res);
}

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

char	*free_all(char **line)
{
    char *res;

    if (*line && check_newline(*line) >= 0)
        return (output_val(line));
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
		if (check_newline(line) >= 0)
			return (output_val(&line));
		nbytes = read(fd, buf, BUFFER_SIZE);
	}
    if (nbytes < 0)
        return (NULL);
    buf[nbytes] = '\0';
	line = ft_strjoin(line, buf);
	return (free_all(&line));
}
