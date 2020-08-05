/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejong_the_great <sejong_the_great@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:29:40 by dachung           #+#    #+#             */
/*   Updated: 2020/08/05 20:41:22 by sejong_the_      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (s == 0)
		return (0);
	while (*s != c)
	{
		if (*s == 0)
			return (0);
		++s;
	}
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	while (len-- > 0 && start < s_len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = -1;
	while (s1[++i] != 0)
		str[i] = s1[i];
	j = 0;
	while (s2[j] != 0)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char const *s1)
{
	char	*temp;
	int		len;
	int		i;

	len = ft_strlen(s1);
	if (!(temp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len-- > 0)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
