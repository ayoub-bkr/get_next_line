/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 01:52:44 by aboukent          #+#    #+#             */
/*   Updated: 2025/01/16 18:05:49 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		a;
	char	*str;

	a = open("text", O_RDONLY);
	str = get_next_line(a);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(a);
	}
	free(str);
	close(a);
}
