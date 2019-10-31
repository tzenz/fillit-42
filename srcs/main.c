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

int		part(char *s)
{
	int 	count1;
	int 	count2;
	int 	count3;
	int 	count4;
	int 	flag;
	int		i;

	count1 = 0;
	count2 = 0;
	count3 = 0;
	count4 = 0;
	flag = 1;
	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == '#')
			count1++;
		if (s[i + 5] == '#')
			count2++;
		if (s[i + 10] == '#')
			count3++;
		if (s[i + 15] == '#')
			count4++;
		i++;
	}
	printf("1 - %d\n2 - %d\n3 - %d\n4 - %d\n", count1, count2, count3, count4);
	return (0);
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
	part(s);
	return (0);
}


