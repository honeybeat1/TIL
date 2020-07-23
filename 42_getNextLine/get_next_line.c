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

#include <get_next_line.h>

int get_next_line(int fd, char **line)
{
    char buf[14];
    static char *s_rest;
    int n_bytes; //읽은 바이트 수
    char *line;

    while ((n_bytes = read(fd, buf, sizeof(buf))) > 0) //읽을 게 있다면
    {
        buf[n_bytes] = '\0'; //읽어온 문자열 마지막 null로 닫아주고
        if ((line = ft_strchr(buf, '\n')) != 0)
        {
            
        }
    }    
}
