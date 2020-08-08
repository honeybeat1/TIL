/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <dachung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:29:07 by dachung           #+#    #+#             */
/*   Updated: 2020/07/23 23:37:50 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char const *s1);
int		if_find_nl_yes(char *buf, char **s_rest, char *find_nl, char **line);
void	if_find_nl_no(char *buf, char **line);
int		if_buf(int fd, char *buf, char **s_rest, char **line);
int		if_s_rest(char *buf, char **s_rest, char **line);
#endif
