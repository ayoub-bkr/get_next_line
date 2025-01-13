/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 08:53:54 by aboukent          #+#    #+#             */
/*   Updated: 2025/01/12 09:33:28 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*before_nl(char *line)
{
	int	i;
	char	*returned_line;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		returned_line = ft_substr(line, 0, i + 1);
	else
		returned_line = line;
	return (returned_line);
}

char	*after_nl(char *line)
{
	int	i;
	int	j;
	char	*returned_line;

	i = 0;
	j = ft_strlen(line);
	while (line[i] != '\n')
		i++;
	if (line[i] == '\n')
		returned_line = ft_substr(line, i + 1, j - i);
	return (returned_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	char		*returned_line;
	char		*temp;
	int			len;
	int			i;

	i = 0;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	len = 1;
	while (!ft_strchr(line, '\n'))
	{
		if (len > 0)
		{
			len = read(fd, buff, BUFFER_SIZE);
			// printf("%d\n", len);
			buff[len] = '\0';
			line = ft_strjoin(line, buff);
		}
		else
		{
			returned_line = line;
			return (returned_line);
		}
	}
	free(buff);
	temp = line;
	// while (line[i] && line[i] != '\n')
	// 	i++;
	// printf("/%s/", line);
	// if (line[i] == '\n')
	// 	free(temp);
	returned_line = before_nl(line);
	line = after_nl(line);
	return (returned_line);
}
