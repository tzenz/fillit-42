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
int		valid(char *s);

int		part1(char *s)
{
	int 	count;
	int 	flag;
	int		i;
	int 	j;

	count = 1;
	i = 0;
	j = 0;
	flag = 0;
	while (s[i] != '#')
		i++;
	while (j < 3)
	{
		if (s[i] == s[i + 1])
		{
			i++;
			count++;
		}
		else if (s[i] == s[i + 5])
		{
			i += 5;
			count++;
		}
		ft_putnbr(count);
		j++;
	}
	return ((count == 4)) ? 0 : -1;
}

int		main(void)
{
	char *s;
	char buf[100];
	int fd;
	int r;

	fd = open("testease", O_RDONLY);
	s = ft_strnew(1);
	while ((r = (read(fd, buf, 100))))
	{
		buf[r] = '\0';
		s = ft_strjoin(s, buf);
	}
	if (valid(s) < 0)
		return (-1);
	ft_putnbr(part1(s));
	return (0);
}


