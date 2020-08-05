/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <dachung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:29:40 by dachung           #+#    #+#             */
/*   Updated: 2020/07/23 23:29:52 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     get_next_line(int fd, char **line)
{
    char            buf[BUFFER_SIZE + 1];
    static char     *s_rest;
    int             n_bytes;
    char            *piece;
    char            *find_nl;
    char            *temp;
    char            *temp2;

    if (fd < 0 || line == NULL || read(fd, buf, 0) < 0 || BUFFER_SIZE < 1)
        return (-1);
    if (!(*line = ft_strdup("")))
        return (-1);
    if (s_rest)
    {
        if ((find_nl = ft_strchr(s_rest, '\n')) != 0)
        {
            piece = ft_substr(s_rest, 0, find_nl - s_rest);
            temp = *line;
            *line = ft_strjoin(*line, piece);
            free(temp);
            free(piece);
            temp2 = s_rest;
            s_rest = ft_strdup(find_nl + 1);
            free(temp2);
            return (1);
        }
        else
        {
            temp = *line;
            *line = ft_strdup(s_rest);
            free(temp);
            free(s_rest);
            s_rest = 0;
        }
    }
    while ((n_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[n_bytes] = '\0';
        if ((find_nl = ft_strchr(buf, '\n')) != 0)
        {
            piece = ft_substr(buf, 0, find_nl - buf);
            temp = *line;
            *line = ft_strjoin(*line, piece);
            s_rest = ft_strdup(find_nl + 1);
            free(temp);
            free(piece);
            return(1);
        }
        else
        {
            temp = *line;
            *line = ft_strjoin(*line, buf);
            free(temp);
        }
    }
    return (0);
}

int main(void)
{
    char *line = 0;
    while (get_next_line(0, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    printf("%s\n", line);
    free(line);
    return (0);
}