#include "get_next_line.h"

void	*check_null(char **buffer, char **storing)
{
	if (!*buffer)
	{
		free(*storing);
		*storing = NULL;
		return (NULL);
	}
	else if (!*storing)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	return (*buffer);
}

int		ft_find(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_get(char **storing, int place_nline)
{
	char	*line;
	if (!*storing)
		return (NULL);
	line = ft_substr(*storing, 0, place_nline + 1);
	*storing = ft_stored_string(storing, place_nline + 1);
	return (line);
}

char	*ft_stored_string(char **str, int place_nline)
{
	char	*remember;
	size_t	len_str;

	if (!*str)
		return (NULL);
	len_str = ft_strlen(*str);
	remember = ft_substr(*str, place_nline, len_str);
	free(*str);
	*str = NULL;
	return (remember);
}

char	*get_next_line(int fd)
{
	static char	*stord;
	char		*buff;
	int			read_return;

	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!stord)
		stord = ft_strdup("");
	if (check_null(&buff, &stord) == NULL)
		return (NULL);
	read_return = read(fd, buff, BUFFER_SIZE);
	while (read_return >= 0)
	{
		buff[read_return] = '\0';
		stord = ft_strjoin(stord, buff);
		if (!stord)
			break;
		if (ft_find(stord) != -1)
			return (free(buff), ft_get(&stord, ft_find(stord)));
		if (!read_return && !stord[0])
			break ;
		if (!read_return)
			return (free(buff), ft_stored_string(&stord, 0));
		read_return = read(fd, buff, BUFFER_SIZE);
	}
	return (free(buff), free(stord), (stord = NULL), NULL);
}
