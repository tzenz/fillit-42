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
int		valid1(char *s);
int		valid2(char *s, char sim);

char	*addline(char *s)
{
	char 	*str;
	int 	count;
	int 	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			count++;
		i++;
	}
	count++;
	str = ft_strnew(20);
	i = 0;
	while (str[i])
	{
		str[i] = '.';

		if (i == 3 || i == 8 || i == 13 || i == 18)
		{
			str[i + 1] = '\n';
			i++;
		}
		i++;
	}
	ft_putstr(str);
	return (str);
}

int		reason(char *s)
{
	char	*print;

	print = addline(s);
	return (0);
}

int		main(void)
{
	char *s;
	char buf[100];
	char sim;
	int fd;
	int r;
	int i;

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
    reason(s);
	//ft_putstr(s);
	return (0);
}


