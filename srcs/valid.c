/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:57:50 by tzenz             #+#    #+#             */
/*   Updated: 2019/10/31 11:57:51 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <stdio.h>

int		valid(char *s)
{
	int 	i;
	int 	j;
	int 	m;
	int		count;

	i = 0;
	m = 5;
	count = 0;
	while (s[i])
	{
		while (s[i] != '\n')
		{
			if ((s[i] != '#' && s[i] != '.') || i >= (m - 1))
			{
				ft_putchar('M');
				return (-1);
			}
			if (s[i] == '#')
				count++;
			i++;
		}
//		printf ("i - %d   ", i - 1);
//		printf ("m - %d\n", m);
		if (i < (m - 1) && s[i - 1] != '\n')
		{
			ft_putchar('A');
			return (-1);
		}
		if (s[i - 1] != '\n')
			m = m + 5;
		if ((s[i] == '\n' && s[i + 1] == '\n') || s[i + 1] == '\0')
		{
			if (count != 4)
			{
				ft_putchar('B');
				return (-1);
			}
			count = 0;
			m++;
		}
		if (s[i] == '\n' && s[i + 1] == '\n' && s[i + 2] == '\n')
		{
			ft_putchar('C');
			return (-1);
		}
		i++;
	}
	return (0);
}
