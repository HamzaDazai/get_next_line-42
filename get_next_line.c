/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:38:24 by hdazia            #+#    #+#             */
/*   Updated: 2024/12/03 20:47:30 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*get_next_line(int fd)
{
	static char	*storing;
	char		*buffer;
	char		*line;
	int			read_return;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!storing)
		storing = ft_strdup("");
	if (check_null(&buffer, &storing) == NULL)
		return (NULL);
	read_return = read(fd, buffer, BUFFER_SIZE);
	while (read_return >= 0)
	{
		buffer[read_return] = '\0';
		storing = ft_strjoin(storing, buffer);
		if (ft_find_newline(storing) != -1)
			return (free(buffer),
				ft_get_line(&storing, &line, ft_find_newline(storing)));
		if (!read_return && !storing[0])
			break ;
		if (!read_return)
			return (free(buffer), ft_stored_string(&storing, 0));
		read_return = read(fd, buffer, BUFFER_SIZE);
	}
	return (free(buffer), free(storing), (storing = NULL), NULL);
}

int	ft_find_newline(const char *str)
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

char	*ft_get_line(char **storing, char **line, int place_nline)
{
	if (!*storing)
		return (NULL);
	*line = ft_substr(*storing, 0, place_nline + 1);
	*storing = ft_stored_string(storing, place_nline + 1);
	return (*line);
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
