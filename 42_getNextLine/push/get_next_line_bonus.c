/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejong_the_great <sejong_the_great@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:29:40 by dachung           #+#    #+#             */
/*   Updated: 2020/08/05 21:18:34 by sejong_the_      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		if_find_nl_yes(char *buf, char **s_rest, char *find_nl, char **line)
{
	char	*piece;
	char	*temp;

	if (*s_rest)
		piece = ft_substr(*s_rest, 0, find_nl - *s_rest);
	else
		piece = ft_substr(buf, 0, find_nl - buf);
	temp = *line;
	*line = ft_strjoin(*line, piece);
	free(temp);
	free(piece);
	if (*s_rest)
	{
		temp = *s_rest;
		*s_rest = ft_strdup(find_nl + 1);
		free(temp);
	}
	else
		*s_rest = ft_strdup(find_nl + 1);
	return (1);
}

void	if_find_nl_no(char *buf, char **line)
{
	char	*temp;

	temp = *line;
	*line = ft_strjoin(*line, buf);
	free(temp);
}

int		if_buf(int fd, char *buf, char **s_rest, char **line)
{
	int		n_bytes;
	char	*find_nl;

	while ((n_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n_bytes] = '\0';
		if ((find_nl = ft_strchr(buf, '\n')) != 0)
		{
			if_find_nl_yes(buf, s_rest, find_nl, line);
			return (1);
		}
		else
			if_find_nl_no(buf, line);
	}
	return (0);
}

int		if_s_rest(char *buf, char **s_rest, char **line)
{
	char	*find_nl;

	if ((find_nl = ft_strchr(*s_rest, '\n')) != 0)
	{
		if_find_nl_yes(buf, s_rest, find_nl, line);
		return (1);
	}
	else
	{
		if_find_nl_no(*s_rest, line);
		free(*s_rest);
		*s_rest = 0;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*s_rest[OPEN_MAX];

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	if (s_rest[fd])
	{
		if (if_s_rest(buf, &s_rest[fd], line) == 1)
			return (1);
	}
	if (if_buf(fd, buf, &s_rest[fd], line) == 1)
		return (1);
	return (0);
}

// int		main(void)
// {
// 	int	fd1;
// 	int	fd2;
// 	char *line;

// 	fd1 = open("test.txt", O_RDONLY);
// 	fd2 = open("abcde.txt", O_RDONLY);
// 	line = 0;
// 	while (get_next_line(fd1, &line) > 0)
// 	{
// 		printf("%s\n", line);
// 		get_next_line(fd2, &line);
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	get_next_line(0, &line);
// 	free(line);
// 	return (0);
// }