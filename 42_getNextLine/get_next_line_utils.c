/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dachung <dachung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:29:26 by dachung           #+#    #+#             */
/*   Updated: 2020/07/23 23:29:51 by dachung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i); 
}

char *ft_strchr(const char *s, int c)
{
    char *temp;

    temp = (char *)s;
    while (temp > 0)
        if (*temp++ == c)
            return (temp - 1);
    if (c == '\0')
        return (temp);
    else
        return (NULL);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub;
    size_t i;
    size_t s_len;

    if (!s)
        return (NULL);
    if(!(sub = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = 0;
    s_len = ft_strlen(s);
    while (len-- > 0 && start < s_len)
        sub[i++] = s[start++];
    sub[i] = '\0';
    return (sub);
}
