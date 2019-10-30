/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:37:14 by tzenz             #+#    #+#             */
/*   Updated: 2019/10/30 14:37:16 by tzenz            ###   ########.fr       */
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
	j = 20;
	count = 0;
	while (s[i])
	{
		while (s[i] != '\n')
		{
			if ((s[i] != '#' && s[i] != '.') || i >= (m - 1))
				return (-1);
			if (s[i] == '#')
				count++;
			i++;
		}
		printf ("i - %d   ", i - 1);
		printf ("m - %d\n", m);
		if ((i < (m - 1) && s[i - 1] != '\n'))
			return (-1);
		if (s[i - 1] != '\n')
			m = m + 5;
		if (s[i] == '\n' && s[i + 1] == '\n')
			m++;
		if (s[i] == '\n' && s[i + 1] == '\n' && s[i + 2] == '\n')
			return (-1);
		i++;
	}
	return (0);
}

int		main(void)
{
	char *s;
	char buf[100];
	int fd;
	int r;

	fd = open("test", O_RDONLY);
	s = ft_strnew(1);
	while ((r = (read(fd, buf, 100))))
	{
		buf[r] = '\0';
		s = ft_strjoin(s, buf);
	}
	ft_putnbr(valid(s));
	return (0);
}


