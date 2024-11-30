/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:37:32 by hdazia            #+#    #+#             */
/*   Updated: 2024/11/30 02:15:54 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE
#include <unistd.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
char *ft_strdup(const char *s1);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlen(const char *str);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_stored_string(char **str, int palce_nline);
char *ft_get_line(char **storing, char **line, int palce_nline);
int ft_find_newline(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif