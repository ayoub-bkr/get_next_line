/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:41:25 by aboukent          #+#    #+#             */
/*   Updated: 2024/12/15 11:41:27 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*m;
	char	*str;

	i = 0;
	m = malloc(ft_strlen(s) + 1);
	if (!m)
		return (0);
	while (s[i])
	{
		*(m + i) = s[i];
		i++;
	}
	*(m + i) = '\0';
	str = m;
	//free(m);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*m;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (ft_strdup(s1));
	m = (char *)malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!m)
		return (0);
	while (s1[i])
	{
		m[i] = s1[i];
		i++;
	}
	while (s2[j])
		m[i++] = s2[j++];
	m[i] = '\0';
	free(s1);
	str = m;
	//free(m);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*m;
	//char *str;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	m = (char *) malloc(len + 1);
	if (!m)
		return (0);
	while (i < len)
	{
		m[i] = s[start + i];
		i++;
	}
	m[i] = '\0';
	// str = m;
	// free(m);
	return (m);
}