/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:38:24 by hdazia            #+#    #+#             */
/*   Updated: 2024/11/30 18:04:32 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storing;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			read_return;
	int			place_nline;

	if (!storing)
		storing = ft_strdup("");
	read_return = read(fd, buffer, BUFFER_SIZE);
	while (read_return >= 0)
	{
		buffer[read_return] = '\0';
		storing = ft_strjoin(storing, buffer);
		place_nline = ft_find_newline(storing);
		if (place_nline != -1)
			return (ft_get_line(&storing, &line, place_nline));
		if (!read_return && !storing[0])
			break ;
		if (!read_return)
			return (ft_stored_string(&storing, 0));
		read_return = read(fd, buffer, BUFFER_SIZE);
	}
	free(storing);
	storing = NULL;
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
