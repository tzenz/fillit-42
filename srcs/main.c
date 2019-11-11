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

int		reason(char *s)
{
	char *print;
	int count;
	int flag;
	int stop;
	int i;
	int j;

	stop = 21;
	flag = 0;
	i = 0;
	j = 0;
	print = addline(s);
	while (print[i] && !flag)
	{
		if (print[i] == '.')
		{
			count = 0;
			while (s[j] != 'A' && s[j] != 'B' && s[j] != 'C' && s[j] != 'D')
				j++;
			print[i + count++] = s[j++];
			while (j < stop)
			{
				if (s[j] == 'A')
				{
					print[i + count] = s[j];
					count++;
					j++;
//					printf("ONE\n");
				}
				else
				{
					while (s[j] != 'A' && j < stop)
					{
						count++;
						j++;
					}
//					printf("TWO\n");
					print[i + count++] = s[j];
					j++;
				}
				if (s[j] == '\0')
					flag = 1;
				printf("count - %d\n", count);
			}
		}
		stop *= 2;
		i++;
	}
	ft_putstr(print);
	printf("\nj - %d\n", j);
	printf("stop - %d\n", stop);
	return (0);
}

int		main(void)
{
	char	*s;
	char	buf[100];
	char	sim;
	int		fd;
	int		r;
	int		i;

	i = 0;
	fd = open("test", O_RDONLY);
	s = ft_strnew(1);
	while ((r = (read(fd, buf, 100))))
	{
		buf[r] = '\0';
		s = ft_strjoin(s, buf);
	}
	if (valid1(s) < 0)
		return (-1);
	sim = 'A';
	while (s[i])
	{
        if (valid2(&s[i], sim++) < 0)
        	return (-1);
        i += 21;
    }
//    ft_putstr(s);
    reason(s);
	return (0);
}