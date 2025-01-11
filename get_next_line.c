/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:40:27 by aboukent          #+#    #+#             */
/*   Updated: 2024/12/15 11:40:57 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check(char *buff)
{
    int i;

    if (!buff)
        return (0);
    i = 0;
    while (buff[i])
    {
        if (buff[i] == '\n')
        {
            if (buff != NULL)
                free(buff);
            return (1);
        }
        i++;
    }
    return (0);
}

char *append(char **line)
{
    char *returned_line;
    char *temp;
    int i;
    int pause;

    i = 0;
    while((*line)[i])
    {
        if ((*line)[i] == '\n')
            break;
        i++;
    }
    returned_line  = ft_substr(*line, 0, i + 1);
    pause = ft_strlen(*line) - i;
    temp = *line;
    *line = ft_substr(temp, i + 1, pause);
    free(temp);
    return(returned_line);
}

char *get_next_line(int fd)
{
    static char *line;
    int len;
    char *buff;
    char *temp;

    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    while (check(buff) == 0)
    {
        if ((len = read(fd, buff, BUFFER_SIZE)) > 0)
        {
            buff[len] = '\0';
            temp = line;
            line = ft_strjoin(temp, buff);
            free(temp);
            if (!line)
                return (NULL);
        }
        else
            return (append(&line));
    }
    return (append(&line));
}