/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlammert <mlammert@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 16:54:01 by mlammert      #+#    #+#                 */
/*   Updated: 2021/12/14 21:27:04 by mlammert      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	int		len;
	char	*s2;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	len = 0;
	while (s1[len] && s1[len] != '\n')
	{
		s2[len] = s1[len];
		len++;
	}
	if (s1[len] == '\n')
	{
		s2[len] = s1[len];
		len++;
	}
	s2[len] = '\0';
	return (s2);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strs;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strs = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!strs)
		return (NULL);
	strs[len_s1 + len_s2] = '\0';
	ft_strlcpy(strs, s1, len_s1);
	ft_strlcpy(strs + len_s1, s2, len_s2);
	free(s1);
	s1 = NULL;
	return (strs);
}

void	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (!src)
		return ;
	i = 0;
	while (src[i] != '\0' && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	unsigned int	k;

	k = 0;
	if ((unsigned int)ft_strlen(s) < start)
	{
		return (ft_strdup(""));
	}
	i = ft_strlen(s + start);
	if (i < len)
		len = i;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (k < len)
	{
		substr[k++] = (char)s[start];
		start++;
	}
	substr[k] = '\0';
	return (substr);
}
