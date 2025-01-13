/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:40:27 by aboukent          #+#    #+#             */
/*   Updated: 2025/01/12 01:28:41 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	clear(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

// int	check(char *buff)
// {
// 	int	i;

// 	i = 0;
// 	if (!buff)
// 		return (0);
// 	while (buff[i])
// 	{
// 		if (buff[i] == '\n')
// 		{
// 			// buff = clear(buff);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

char	*append(char **line)
{
	char	*returned_line;
	char	*temp;
	int		i;
	int		pause;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\n')
			break ;
		i++;
	}
	temp = *line;
	returned_line = ft_substr(*line, 0, i + 1);
	pause = ft_strlen(*line) - i;
	*line = ft_substr(temp, i + 1, pause);
	clear(&temp);
	if (**line == '\0')
		clear(line);
	return (returned_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	int			len;
	char		*buff;
	char		*temp;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchr(buff, '\n'))
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len > 0)
		{
			buff[len] = '\0';
			temp = line;
			line = ft_strjoin(temp, buff);
			clear(&temp);
			if (!line)
			{
				clear(&buff);
				return (NULL);
			}
		}
		else
		{
			// clear(&buff);
			return (append(&line));
		}
	}
	// clear(&buff);
	return (append(&line));
}
