/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 08:24:30 by hdazia            #+#    #+#             */
/*   Updated: 2024/12/01 09:12:28 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*storing[255];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			read_return;
	int			place_nline;

	if (!storing[fd])
		storing[fd] = ft_strdup("");
	read_return = read(fd, buffer, BUFFER_SIZE);
	while (read_return >= 0)
	{
		buffer[read_return] = '\0';
		storing[fd] = ft_strjoin(storing[fd], buffer);
		place_nline = ft_find_newline(storing[fd]);
		if (place_nline != -1)
			return (ft_get_line(&storing[fd], &line, place_nline));
		if (!read_return && !storing[fd][0])
			break ;
		if (!read_return)
			return (ft_stored_string(&storing[fd], 0));
		read_return = read(fd, buffer, BUFFER_SIZE);
	}
	free(storing[fd]);
	storing[fd] = NULL;
	return (NULL);
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
	*line = ft_substr(*storing, 0, place_nline + 1);
	*storing = ft_stored_string(storing, place_nline + 1);
	return (*line);
}

char	*ft_stored_string(char **str, int place_nline)
{
	char	*remember;
	size_t	len_str;

	len_str = ft_strlen(*str);
	remember = ft_substr(*str, place_nline, len_str);
	free(*str);
	*str = NULL;
	return (remember);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
