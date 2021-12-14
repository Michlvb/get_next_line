#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif