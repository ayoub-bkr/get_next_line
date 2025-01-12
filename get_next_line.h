/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:38:00 by aboukent          #+#    #+#             */
/*   Updated: 2025/01/12 01:49:17 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char		*get_next_line(int fd);
char		*put(char *buff, int len);
char		*ft_strdup(char *s);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);

#endif
