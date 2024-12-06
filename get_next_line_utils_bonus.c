#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = ft_strlen(s1);
	str = malloc (sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*check_nu(char *s1, char *s2)
{
	if (s1 == NULL)
		return ((char *)s2);
	return ((char *)s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int			i;
	int			j;
	char		*p;
	int			s1_len;
	int			s2_len;

	j = 0;
	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(check_nu(s1, s2)));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (p == NULL)
		return (NULL);
	while (i < s1_len)
	{
		p[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		p[i++] = s2[j++];
	return (p[i] = '\0', free(s1), p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ds;
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ds = (char *)malloc((len + 1) * sizeof(char));
	if (ds == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ds[i] = s[start + i];
		i++;
	}
	ds[i] = '\0';
	return (ds);
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
