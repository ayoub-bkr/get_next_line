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
            return (1);
        i++;
    }
    return (0);
}

char *append(char **line)
{
    char *returned_line;
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
    *line = ft_substr(*line, i + 1, pause);
    return(returned_line);
}



char *get_next_line(int fd)
{
    static char *line;
    int len;
    char *buff;
    //char *returned_line;
    char *second_line;
    //int i = 0;

    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    while (check(buff) == 0)
    {
        if ((len = read(fd, buff, BUFFER_SIZE)) > 0)
        {
            buff[len] = '\0';
            second_line = line;
            line = ft_strjoin(second_line, buff);
            if (!line)
                return (NULL);
            
            // buff[len] = '\0';
            // second_line = line;
            // line = ft_strjoin(second_line, buff);
            // if (!line)
            //     return (NULL);
            // returned_line = append(&line);
        }
        else
        {
            // while(line[i])
            // {
            //     if (line[i] == '\n')
            //         break;
            //     i++;
            // }
            // returned_line  = ft_substr(line, 0, i + 1);
            // int pause = ft_strlen(line) - i;
            // line = ft_substr(line, i + 1, pause);
            // return (returned_line);
            return (append(&line));
        }
    }
    free (buff);
    // while(line[i])
    //         {
    //             if (line[i] == '\n')
    //                 break;
    //             i++;
    //         }
    // returned_line  = ft_substr(line, 0, i + 1);
    // int pause = ft_strlen(line) - i;
    // line = ft_substr(line, i + 1, pause);
    // if (*line == '\0')
    // {
    //     free (line);
    //     line = NULL;
    // }
    // printf("%s", returned_line);
    // printf("next: {%s}\n", line);
    return (append(&line));
}