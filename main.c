/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 01:52:44 by aboukent          #+#    #+#             */
/*   Updated: 2025/01/12 01:54:03 by aboukent         ###   ########.fr       */
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
	printf("%s", str);
	free(str);
	str = get_next_line(a);
	printf("%s", str);
	free(str);
	close(a);
}
