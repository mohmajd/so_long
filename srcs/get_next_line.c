#include "get_next_line.h"
static char	*ft_read(int fd, char *old)
{
	char	*buffer;
	char	*tmp;
	int		count;

	if (ft_strchr(old, '\n'))
		return (old);
	buffer = malloc(1);
	buffer[0] = '\0';
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
	{
		free (buffer);
		return (NULL);
	}
	tmp[BUFFER_SIZE] = '\0';
	count = read(fd, tmp, BUFFER_SIZE);
	while (count > 0)
	{
		tmp[count] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
		count = read(fd, tmp, BUFFER_SIZE);
	}
	return (free(tmp), free (buffer), ft_strjoin(old, buffer));
}

static char	*ft_line(char *str)
{
	int		y;
	int		i;
	char	*line;

	if (*str == '\0')
		return (NULL);
	y = 0;
	while (str[y] != '\0' && str[y] != '\n' && (str[y] > 31 && str[y] < 127))
		y++;
	if (str[y] == '\n')
		line = malloc(y + 2);
	if (str[y] == '\0')
		line = malloc(y + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < y)
	{
		line[i] = str[i];
		i++;
	}
	if (str[y] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_rest(char *str)
{
	char	*start;
	char	*rest;

	start = ft_strchr(str, '\n');
	if (start != NULL)
		start++;
	if (start == NULL || *start == '\0')
	{
		free (str);
		return (NULL);
	}
	rest = malloc(ft_strlen(start) + 1);
	if (!rest)
		return (NULL);
	ft_strcpy(rest, start);
	return (free (str), rest);
}


char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, rest);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	rest = ft_rest(buffer);
	return (line);
}