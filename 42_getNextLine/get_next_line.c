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

int get_next_line(int fd, char **line)
{
    char buf[14];
    static char *s_rest;
    int n_bytes; //읽은 바이트 수
    char *piece;
    char *find_nl;
    char *temp;

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
            free(s_rest); //여기서 해주는 이유?
            s_rest = ft_strdup(find_nl + 1);
            return (1);
        }
        else
        {
            temp = *line;
            *line = ft_strdup(s_rest);
            free(temp);
            free(s_rest);
            s_rest = 0; //free해주면 쓰레기값이 들어가기때문에 0으로 초기화 보통 포인터 free해주면 초기화해줌
        }
    }
    while ((n_bytes = read(fd, buf, 13)) > 0) //읽을 게 있다면
    {
        buf[n_bytes] = '\0'; //읽어온 문자열 마지막 null로 닫아주고
        //printf("%s\n", buf);
        if ((find_nl = ft_strchr(buf, '\n')) != 0)
        {
            piece = ft_substr(buf, 0, find_nl - buf);
            temp = *line;
            *line = ft_strjoin(*line, piece);
            s_rest = ft_strdup(find_nl + 1); //뉴라인 가리키는 포인터 이동
            //printf("중간 : %s end\n", s_rest);
            free(temp); //free 해주려고 
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
